class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        
        int la = a.length() - 1, lb = b.length()-1;
        int carry =0;
        while(la>=0  || lb>=0 ||  carry){
            if(la>=0){
                carry+= (a[la]-'0');
                la--;

            }
            if(lb>=0){
                carry+= (b[lb]-'0');
                lb--;

            }
            ans.push_back(carry%2 + '0');
            carry/=2;

            
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
};