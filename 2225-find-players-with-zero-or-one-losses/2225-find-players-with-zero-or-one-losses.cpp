class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> ans1,ans2;
        unordered_map<int,int> losses;
        set<int> players;

        for(auto&m:matches){
            int loser=m[1];
            int winner=m[0];

            losses[loser]++;

            players.insert(m[0]);
            players.insert(m[1]);
        }
        for(int p:players){
            if(losses.find(p)==losses.end()){
                ans1.push_back(p);
            }
            else if(losses[p]==1){
                ans2.push_back(p);
            }
        }
        return {ans1,ans2};
    }
};