class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i=0; 
        for(auto n:v){
            if(i<2 || v[i-2]!=n){
                v[i]=n;
                i++;
            }
        }
        return i;
       
    }
};