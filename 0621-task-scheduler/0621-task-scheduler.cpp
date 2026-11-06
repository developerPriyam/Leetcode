class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        int MF=0,CM=0;
        for(int i=0;i<26;i++){
            if(freq[i]>MF){
                MF=freq[i];
                CM=1;
            }
            else if(freq[i]==MF){
                CM++;
            }
        }
        int ans=max((int)tasks.size(),(MF-1)*(n+1)+CM);
        return ans;
    }
};