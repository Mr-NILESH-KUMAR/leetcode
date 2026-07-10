class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        vector <int> v(2,0);
        
        for(int i=0 ;i<bills.size();i++){
            if(bills[i]==5){
                v[0]++;
            }
            else if(bills[i]==10){
                if(v[0]>0){ v[0]--;
                v[1]++;}
                else return false;
            }
            else{
                if(v[1]>0 && v[0]>0){
                    v[1]--;
                    v[0]--;
                }
                else if(v[0]>=3)v[0]-=3;
                else return false;
            }
        }
        return true;
    }
};