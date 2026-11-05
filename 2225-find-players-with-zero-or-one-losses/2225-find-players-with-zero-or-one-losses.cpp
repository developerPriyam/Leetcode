class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> m;
       
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
        return ans;
    }
};