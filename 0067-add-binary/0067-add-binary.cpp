class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string binary;
        while(i>=0||j>=0||carry){
            int bitA=0;
            int bitB=0;
            if(i>=0){
                bitA=a[i]-'0';
                i--;
            }
            if(j>=0){
                bitB=b[j]-'0';
                j--;
            }
            int sum=bitA+bitB+carry;
            binary+=to_string(sum%2);

            carry=sum/2;
        }
        reverse(binary.begin(),binary.end());
        return binary;
        
    }
};