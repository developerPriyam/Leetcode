class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string start=max(arriveAlice,arriveBob);
        string end=min(leaveAlice,leaveBob);
        if(start>end){
            return 0;
        }
        int days[]={0,31,59,90,120,151,181,212,243,273,304,334};
        int sM=stoi(start.substr(0,2));
        int sD=stoi(start.substr(3,2));
        int eM=stoi(end.substr(0,2));
        int eD=stoi(end.substr(3,2));
    
        int startNum=days[sM-1]+sD;
        int endNum=days[eM-1]+eD;
        return endNum-startNum+1;
    
    }
};