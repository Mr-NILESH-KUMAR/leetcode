class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n+1, 0);

        for(int i : citations){
            if(i >= n){
                freq[n]++;
            }
            else{
                freq[i]++;
            }
        }

        int cnt = 0;

        for(int i = n; i >= 0; i--){
            cnt += freq[i];

            if(cnt >= i){
                return i;
            }
        }
        return 0;
    }
};