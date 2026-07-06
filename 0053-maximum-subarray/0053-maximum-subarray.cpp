class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN,mxs=0;
        int i=0;
        for(int i=0 ;i<nums.size() ; i++){
                mxs+=nums[i];
            
                mx=max(mx,mxs);
            if((mxs)<=0) mxs=0;
            
        }
        return mx;
    }
};