class Solution {
public:
    long long MOD1 = 1000000007;
    long long MOD2 = 1000000009;
    long long BASE1 = 131;
    long long BASE2 = 137;

    vector<long long> h1, h2, p1, p2;

    bool check(int len, int n) {
        unordered_map<unsigned long long, int> freq;

        for (int i = 0; i + len <= n; i++) {
            long long hash1 =
                (h1[i + len] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;
            long long hash2 =
                (h2[i + len] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

            unsigned long long key = (hash1 << 32) | hash2;
            freq[key]++;
        }

        for (auto& [key, count] : freq) {
            if (count == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;

            p1[i + 1] = p1[i] * BASE1 % MOD1;
            p2[i + 1] = p2[i] * BASE2 % MOD2;
        }

        int left = 1, right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (check(mid, n))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};