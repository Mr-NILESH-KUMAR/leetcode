class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        unordered_map<int, int> hash;

        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        for (auto it : hash) {
            if (it.second > mid) {
                return it.first;
            }
        }

        return -1;
    }
};