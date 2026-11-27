class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minnPrice = INT_MAX;
        vector<int> profit(n, 1);

        for (int i = 0; i < n; i++) {
            minnPrice = min(minnPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    profit[i]++;
                }
            }
        }

        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + profit[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / minnPrice);
        }
        return ans;
    }
};