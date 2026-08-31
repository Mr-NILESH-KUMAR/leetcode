class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lf = *max_element(nums.begin(),nums.end());
        int rt =0;
        for(auto x:nums)rt+=x;
        while(lf<=rt){
            int mid=(lf+rt)>>1;
            int kth=1,sum=0;
            for(int i =0 ;i<nums.size();i++){
                if((sum+nums[i])>mid){
                    sum=nums[i];
                    kth++;
                }
                else sum+=nums[i];

            }
            if(kth<=k)rt=mid-1;
            else lf=mid+1;
        }
        return lf;
        
    }
};