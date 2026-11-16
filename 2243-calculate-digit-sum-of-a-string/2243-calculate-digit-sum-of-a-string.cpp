class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        while(n>k){

            string temp="";
            for(int i=0;i<n;i+=k){
                int sum=0;

                for(int j=i;j<min(i+k,(int)n);j++){
                    sum+=s[j]-'0';

                }
                temp+=to_string(sum);
            }
            s.swap(temp);
            n=s.size();
        }
        return s;
    }
};