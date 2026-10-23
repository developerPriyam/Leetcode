class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteangle=6*minutes;
        double hourangle=30*hour+0.5*minutes;

        double diff=abs(hourangle-minuteangle);

        double ans=min(diff,360-diff);

        return ans;
    }
};