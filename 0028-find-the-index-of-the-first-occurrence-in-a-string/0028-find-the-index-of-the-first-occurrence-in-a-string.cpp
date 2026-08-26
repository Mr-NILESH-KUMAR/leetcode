class Solution {
public:
    int strStr(string h, string n) {
        if(n.length()>h.length()) return -1;
        //if(n==h) return 0;
        for(int i=0; i<=h.length()-n.length(); i++){
            if(n==(h.substr(i,n.length()))){ return i;break ;}
        }
        return -1;
        
    }
};