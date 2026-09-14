class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0,mx=0;
        int st=0,end=0;
         int hash[256];
         fill(hash,hash+256 ,-1);
        

        
        while(end < s.length()){
            if(hash[s[end]]!=-1 && hash[s[end]]>=st){
                st= hash[s[end]]+1;
                
            }
            count=end-st+1;
            mx=max(mx,count);
            hash[s[end]]=end;
            end++;
            



        }
        return mx;
        
    }
};