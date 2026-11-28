class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);

        for (auto& item : items)
            freq[item[0]]++;

        vector<int> gain(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                gain[f] += freq[j];
            }
            gain[f]--;
        }

        vector<array<long long, 3>> opportunities;

        for (auto& item : items) {
            int f = item[0];
            int price = item[1];

            if (gain[f] > 0) {
                opportunities.push_back({price, 2, gain[f]});
            }

            opportunities.push_back({price, 1, LLONG_MAX});
        }

        sort(opportunities.begin(), opportunities.end(),
             [](auto& a, auto& b) { return a[1] * b[0] > b[1] * a[0]; });

        long long ans = 0;

        for (auto& op : opportunities) {
            long long price = op[0];
            long long value = op[1];
            long long limit = op[2];

            long long count = min(limit, budget / price);

            ans += count * value;
            budget -= count * price;
        }

        return ans;
    }
};