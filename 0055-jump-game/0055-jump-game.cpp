class Solution {
public:
    bool canJump(vector<int>& nums) {
        
       int mx =0;
       for(int i=0 ;i<nums.size();i++){
        if(i>mx) return false;
        else
        mx=max(mx,nums[i]+i)  ;  

       }
return true;

    }
};