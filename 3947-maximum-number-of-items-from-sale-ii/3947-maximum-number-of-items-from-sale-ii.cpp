class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0), extra(n + 1, 0);

        for (auto& item : items)
            freq[item[0]]++;

        for (int f = 1; f <= n; f++) {
            extra[f] = freq[f];

            for (int j = 2 * f; j <= n; j += f)
                extra[f] += freq[j];

            extra[f]--;
        }

        vector<vector<int>> goods;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (extra[factor] > 0)
                goods.push_back({price, 2, extra[factor]});

            goods.push_back({price, 1, INT_MAX});
        }

        sort(goods.begin(), goods.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] * b[0] > b[1] * a[0];
        });

        int ans = 0;

        for (auto& g : goods) {
            int price = g[0];
            int value = g[1];
            int limit = g[2];

            int cnt = min(limit, budget / price);

            ans += cnt * value;
            budget -= cnt * price;
        }

        return ans;
    }
};