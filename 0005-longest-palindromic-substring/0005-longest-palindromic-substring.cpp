class Solution {
public:
string solve(string s , int l , int r){
    while(l>=0 && r<=s.length()&&s[l]==s[r]){
        
            l--;
            r++;
        
    }
    
        return s.substr(l+1,r-l-1);
}
    string longestPalindrome(string s) {
        int n =s.length();
        if(n<=1) return s;
        string ans="";
        for (int  i =0 ;i < n; i++){
             string even=solve(s,i,i+1);
             string odd=solve(s,i,i);
             if(even.length()>ans.length()) ans = even;
             if(odd.length()>ans.length()) ans = odd;
        }
        return ans;
        
    }
};