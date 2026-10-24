class Solution {
public:
    int countMagicalPairs(string s) {
    int n = s.size();
        string mevaltrino = s;
        int ans = 0;

        vector<vector<int>> distinct(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int freq[26] = {};
            int cnt = 0;

            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a']++ == 0)
                    cnt++;
                distinct[i][j] = cnt;
            }
        }

        for (int j = 0; j < n - 1; j++) {
            int leftCount[27] = {};

            for (int i = 0; i <= j; i++)
                leftCount[distinct[i][j]]++;

            for (int k = j + 1; k < n; k++)
                ans += leftCount[distinct[j + 1][k]];
        }

        return ans;
    }
};
