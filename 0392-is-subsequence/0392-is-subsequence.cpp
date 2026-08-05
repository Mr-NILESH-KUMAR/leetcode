class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pre=0;
        if(s.empty()) return true;
        for(int i =0 ;i<t.length();i++){
            if(t[i]==s[pre]){
                pre++;
                if(pre>=s.length())return true;
            }
        }
        return false;
        


        
    }
};