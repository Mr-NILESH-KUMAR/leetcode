class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cp=prices[0];
        int maxprofit=0;
        for(int i=0;i<n;i++){
             cp=min(cp,prices[i]);
            int sp=prices[i];
            int profit=sp-cp;
             maxprofit=max(profit,maxprofit);
        }
        if(maxprofit>0)return maxprofit;
        else return 0;
        
    }
};