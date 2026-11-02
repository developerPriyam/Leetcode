class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn=*min_element(nums.begin(),nums.end());
        int n=nums.size();
            int sum=0;
            for(int x:nums){
                sum+=x;
            }
        
        return sum-n*minn;
    }
};