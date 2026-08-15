class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]<nums[1] && nums[0]<nums[n-1]) return nums[0];
        if(nums[n-1]<nums[n-2] && nums[n-1]<nums[0]) return nums[n-1];
        int lf=1,rt=n-2;
        while(lf<=rt){
            int mid = (lf+rt)/2;
           if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]) return nums[mid];
           else if(nums[mid]>nums[rt]) lf=mid+1;
           else rt=mid-1;
        }
        return 0;
        
    }
};