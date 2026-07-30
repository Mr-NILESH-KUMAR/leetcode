class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nb,cnt=0;        

        for (int i = 0; i < n; i++) {
            if(cnt==0)nb=nums[i];
            nb==nums[i] ? cnt++ : cnt--;
        }
        return (cnt > 0) ? nb : -1;
    }
};