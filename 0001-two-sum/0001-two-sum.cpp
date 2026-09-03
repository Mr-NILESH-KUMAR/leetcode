class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mpp;
        
            for(int i=0 ; i<nums.size() ; i++){
                int n = nums[i];
                if(mpp.find(target-n)!=mpp.end()){
                    return {i,mpp[target-n]};
                }
                mpp[n]=i;

            }
            return{};


        
        
    }
};