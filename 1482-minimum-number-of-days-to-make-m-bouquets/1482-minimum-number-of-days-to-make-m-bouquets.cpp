class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)return -1;
        int lf = *min_element(bloomDay.begin(),bloomDay.end());
        int rt = *max_element(bloomDay.begin(),bloomDay.end());
        int ans =INT_MAX;
        while(lf<=rt){
            int mid = lf +(rt-lf)/2;
            int cont=0,M=m;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                  cont++;                                       
                }
                else{
                    M-=(cont/k);
                    cont=0;

                }
            }
            M -= cont / k;
                if(M<=0){
                    ans = min(ans,mid);
                    rt=mid-1;
                }
                else lf=mid+1;
        }
        return ans;
    }
};