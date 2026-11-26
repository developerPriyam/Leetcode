class Solution {
public:
    bool canAliceWin(int n) {
        int move=10;
        int t=0;
        while(n>=move){
            n-=move;
            move--;
            t++;
        }
        return t%2==1;
    }
};