class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int lf = 0, sum = 0, sub = INT_MAX;

        for(int rt = 0; rt < n; rt++) {
            sum += nums[rt];

            while(sum >= target) {
                sub = min(sub, rt - lf + 1);
                sum -= nums[lf];
                lf++;
            }
        }

        return sub == INT_MAX ? 0 : sub;
    }
};