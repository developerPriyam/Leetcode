class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int s=needle.size();
        for(int i=0;i<=n-s;i++){
            if(haystack.substr(i,s)==needle){
                return i;
            }
        }
        return -1;
    }
};