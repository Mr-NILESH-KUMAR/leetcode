class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0,fs=0 ;
        while(i<nums.size()){
            if(fs>=nums.size()){
                nums[i]=0;
                i++;
            }
            else if(nums[fs]!=0){nums[i]=nums[fs]; i++;}
            fs++;


        }
        
    }
};