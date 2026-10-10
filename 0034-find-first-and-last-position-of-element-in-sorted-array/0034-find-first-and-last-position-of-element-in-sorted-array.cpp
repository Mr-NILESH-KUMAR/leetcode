class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=0, mid;
        int l=nums.size()-1;
        int first = -1;
        int last = -1;
        while(f<=l){
            mid = (f+l)/2;
            if(nums[mid]==target){
                first = mid;
                l = mid-1;
            }else if(nums[mid]<target){
                f=mid+1;
            }else{
                l=mid-1;
            }
        }
        f=0, mid;
        l=nums.size()-1;
        while(f<=l){
            mid = (f+l)/2;
            if(nums[mid]==target){
                last = mid;
                f=mid+1;
            }else if(nums[mid]<target){
                f=mid+1;
            }else{
                l=mid-1;
            }
        }
        return {first, last};
    }
};