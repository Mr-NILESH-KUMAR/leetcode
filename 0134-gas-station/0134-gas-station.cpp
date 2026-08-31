class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int n = gas.size();
        long long diff = 0;
        int current = 0;
    
        for(int i = 0; i < n; i++){
            diff+= gas[i]-cost[i];
            current += gas[i]-cost[i];;
            if(current<0){
                ans = i+1;
                current = 0;
            }
        }
        if(diff >= 0) return ans;
        return -1;
    }
};