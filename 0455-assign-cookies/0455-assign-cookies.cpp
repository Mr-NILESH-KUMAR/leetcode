class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int givencount = 0;
        int lf = 0;
        int rt = 0;
        while(lf < g.size() && rt < s.size()){
            if(s[rt] >= g[lf]){
                givencount += 1;
                lf++;
                rt++;
            }else{
                rt++;
            }
        }
        return givencount;
        
    }
};