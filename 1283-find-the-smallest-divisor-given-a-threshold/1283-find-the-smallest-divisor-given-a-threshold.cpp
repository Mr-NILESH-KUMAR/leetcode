class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
       int lf = 1; 
       int rt = *max_element(nums.begin(),nums.end());
       if(nums.size()==th) return rt;
       int ans=0;
       while(lf<=rt){
        int mid = lf+(rt-lf)/2;
        long long the=0;
        for(int i=0;i<nums.size();i++){
            the+=(nums[i]+mid-1)/mid;
            
        }
        if(the<=th){
            rt=mid-1;
            ans=mid;
        }
        else{
            lf=mid+1;
        }

       } 
       return ans;
        
    }
};