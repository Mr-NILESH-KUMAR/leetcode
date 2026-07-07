class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        int pre,pst=pre=prices[0];
        for(int i=0 ;i<prices.size();i++){
            if(pre>prices[i]) {pre=prices[i];pst=prices[i];}
            else if(pst<prices[i]) pst=prices[i];
            prof=max(prof,pst-pre);

        }
        return prof;
        
    }
};