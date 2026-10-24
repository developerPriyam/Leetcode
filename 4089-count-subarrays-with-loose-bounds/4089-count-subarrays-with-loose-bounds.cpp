
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> vornelqixa = nums;

        long long ans = 0;
        long long len = 0;

        for (int x : vornelqixa) {
            if (x >= minK && x <= maxK) {
                len++;
                ans += len;
            } else {
                len = 0;
            }
        }

        return ans;
    }
};
