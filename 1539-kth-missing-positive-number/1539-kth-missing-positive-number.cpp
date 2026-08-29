class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int mis = abs(arr[n-1]-n);
        int lf,rt ;
        
            lf =0,rt=n-1;
            while(lf<=rt){
                int mid = lf+(rt-lf)/2;
                
                if(abs(mid-arr[mid]+1)<k){
                    lf=mid+1;
                }
                else rt=mid-1;
            }


            return k+lf;
        
            
        return k+lf;
        

        
    }
};