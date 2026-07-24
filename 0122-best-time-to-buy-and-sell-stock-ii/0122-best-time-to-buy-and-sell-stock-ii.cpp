class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0,pre=prices[0];

        
        for (int i =1; i<prices.size() ; i++){            
            if(prices[i]>pre){
                prof+=(prices[i]-pre);
                pre = prices[i];
            }
            else pre= prices[i];

        }
        return prof;
    }
};