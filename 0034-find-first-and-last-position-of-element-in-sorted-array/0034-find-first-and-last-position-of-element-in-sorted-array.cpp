class Solution {
public:
    int firstoccurence(vector<int> &nums,int target){
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                ans=mid;
                end=mid-1;//left search
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
    int lastoccurence(vector<int> &nums,int target){
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                ans=mid;
                st=mid+1;//right search
            }
            else if(nums[mid]<target){
                st=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first= firstoccurence(nums,target);
        int last=lastoccurence(nums,target);
        
        return{first,last};
    }
};