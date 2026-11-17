
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int curr = 0;

                    for (int grp = 0; grp < d; grp++) {
                        int l = i + grp;
                        int r = l + (len / d - 1) * d;

                        while (l < r) {
                            if (s[l] != s[r])
                                curr++;

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], curr);
                }
            }
        }

        vector<int> prev(n + 1, INF);
        vector<int> curr(n + 1, INF);

        prev[0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 2 * parts; i <= n; i++) {
                for (int j = 2 * (parts - 1); j <= i - 2; j++) {

                    if (prev[j] == INF) continue;

                    curr[i] = min(curr[i],
                        prev[j] + cost[j][i - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
