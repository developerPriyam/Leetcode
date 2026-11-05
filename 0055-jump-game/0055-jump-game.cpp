class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int MR=0;
        for(int i=0;i<n;i++){
            if(MR<i){
                return false;
            }
            else{
                MR=max(MR,i+nums[i]);
            }
        }
        return true;
    }
};