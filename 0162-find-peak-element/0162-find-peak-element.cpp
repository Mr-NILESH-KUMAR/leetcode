class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int lf = 1,rt=n-2;
        while(lf<rt){
            int mid = (lf+rt)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            else if(nums[mid]<nums[mid+1]){
                lf=mid+1;
            }
            else rt=mid;

        }
        return lf;
    
        
        
    }
};