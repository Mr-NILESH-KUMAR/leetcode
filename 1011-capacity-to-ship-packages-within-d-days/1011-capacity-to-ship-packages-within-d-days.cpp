class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long lf = *max_element(weights.begin(), weights.end());
        long long rt = 0;

        for(auto x : weights) rt += x;

        while(lf <= rt) {
            long long mid = lf + (rt - lf) / 2;

            int day = 1;
            long long sum = 0;

            for(auto x : weights) {
                if(sum + x > mid) {
                    day++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if(day <= days) {
                rt = mid - 1;
            } else {
                lf = mid + 1;
            }
        }

        return lf;
    }
};