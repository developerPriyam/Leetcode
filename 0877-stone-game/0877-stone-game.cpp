class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int evensum=0;int oddsum=0;

        for(int i=0;i<piles.size();i++){
            if(i%2==0)
            evensum+=piles[i];
            else
            oddsum+=piles[i];
        }

        if(evensum>oddsum||oddsum>evensum){
            return true;
        }
        return false;
    }
};