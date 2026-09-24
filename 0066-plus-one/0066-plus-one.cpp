class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int x =v.size()-1;
        for (int i =x ; i>=0 ; i--){
            if(v[i]!=9){
                v[i] ++;
                return v;
            }
            v[i]=0;
        }
        v.insert(v.begin(),1);
        return v;

        
            
                

              
         


        
        

        
    }
};