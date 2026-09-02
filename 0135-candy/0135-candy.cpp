class Solution {
public:
    int candy(vector<int>& rat) {
        int sum=1 ,i=1,n=rat.size();
        while(i<n){
            if(rat[i]==rat[i-1]){
                sum++;i++;continue;
            }
            int peak=1;
            while(i<n && rat[i]>rat[i-1]){
                peak++;sum+=peak;i++;
                
            }
            int depth=1;
            while(i<n && rat[i]<rat[i-1]){
                sum+=depth; i++; depth++;
            }
            if(depth>peak) sum+=(depth-peak);
        }
        return sum;
        
    }
};