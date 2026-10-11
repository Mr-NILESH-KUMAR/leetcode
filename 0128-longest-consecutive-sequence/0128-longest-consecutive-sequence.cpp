class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i : nums){
            st.insert(i);
        }
        int length=0;
        int cnt=1;
        for(auto i :st){
            if(st.find(i-1)==st.end()){
                cnt=1;
            int x=i;
                
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }

            }
            
            
            length=max(length,cnt);
        }
        return length;

        
    }
};