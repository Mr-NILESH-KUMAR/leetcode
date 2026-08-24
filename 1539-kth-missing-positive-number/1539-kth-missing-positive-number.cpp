class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l =0,r = n-1;

        int ans = r;
        while(l <=r){
            int mid = (l+r)>>1;

            if(arr[mid]-(mid+1) >= k) {
                ans = mid;
                r = mid-1;
            } 
            else{
                l = mid+1;
            }
        }

        return l + k;
    }
};