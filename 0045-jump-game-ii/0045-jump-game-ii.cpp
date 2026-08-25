class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& t) {
        int n = nums.size();
        if (i >= n - 1)
            return 0;

        if (t[i] != -1)
            return t[i];

        int mini = n + 5;
        for (int j = 1; j <= nums[i]; j++) {
            int res = 1 + solve(i + j, nums, t);
            mini = min(mini, res);
        }
        return t[i] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 1, -1);
        return solve(0, nums, t);
    }
};