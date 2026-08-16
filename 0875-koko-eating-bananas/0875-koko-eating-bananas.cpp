class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lf = 1;
        int rt = *max_element(piles.begin(), piles.end());
        int ans = rt;

        while (lf <= rt) {
            int mid = lf + (rt - lf) / 2;

            long long hr = 0;

            for (int i = 0; i < piles.size(); i++) {
                hr += (piles[i] + mid - 1) / mid;
            }

            if (hr <= h) {
                ans = mid;
                rt = mid - 1;   
            } 
            else {
                lf = mid + 1;  
            }
        }

        return ans;
    }
};