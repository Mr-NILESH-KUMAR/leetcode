class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lf =1; int rt = n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(lf<=rt){
            int mid = (lf+rt)/2;
            if((nums[mid]!=nums[mid-1])&& nums[mid]!=nums[mid+1]){ return nums[mid];                
            }
            else if((nums[mid]==nums[mid+1] && mid%2==1) ||(nums[mid]==nums[mid-1]&& mid%2==0) ){
                rt=mid;

            }
            else if((nums[mid]==nums[mid+1] && mid%2==0) || nums[mid]==nums[mid-1] && mid%2==1){
                lf=mid+1;
            }

        }
        return nums[0];
        
    }
};