class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int leftprod = 1;
        int rightprod = 1;
        int ans = INT_MIN;

        for(int i = 0; i < n; i++){

            if(leftprod == 0){
                leftprod = 1;
            }

            if(rightprod == 0){
                rightprod = 1;
            }

            leftprod *= nums[i];
            rightprod *= nums[n - 1 - i];

            ans = max(ans, max(leftprod, rightprod));
        }

        return ans;
    }
};