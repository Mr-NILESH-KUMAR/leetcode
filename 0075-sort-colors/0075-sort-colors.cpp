class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector <int> v(3,0);
        for(auto i:nums){
            v[i]++;
        }
        for(int i =0 ;i<nums.size();i++){
            if(v[0]>0)
            {nums[i]=0; v[0]--;}
            else if(v[1]>0){
                nums[i]=1; v[1]--;
            }
            else {
                nums[i]=2;
                v[2]--;
            }
        }

    }
};