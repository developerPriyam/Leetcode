class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> m;
       
        for(auto&match:matches){
            int loser=match[1];
            int winner=match[0];
            m[loser]++;
            m[winner]+=0;
        }
        for(auto it:m){
            if(it.second==0){
                ans[0].push_back(it.first);
            }
            else if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};