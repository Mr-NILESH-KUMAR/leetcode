class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vp;
       int m = matrix.size();
        int n = matrix[0].size();
        for(int i =0; i<m; i++) {
            for(int j =0; j<n; j++) {
                if((matrix[i][j])==0) vp.emplace_back(i,j);
            }
        }
        //after having indices of positions having 0
        //make it all zero
        for(auto & j : vp) {
            int f = j.first;
            int s = j.second;
            for(int i =0; i<m; i++) 
                matrix[i][s]=0;
            for(int i =0; i<n; i++) 
                matrix[f][i]=0;

            
        }
    }
};