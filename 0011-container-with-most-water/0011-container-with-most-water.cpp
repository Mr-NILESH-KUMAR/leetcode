class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int lh = 0,rh=height.size()-1; int mx=0;
        while(lh<rh){
           int weidth = abs(rh-lh);
            int high = min(height[lh],height[rh]);
            int curArea = weidth * high ;
            mx= max(mx,curArea);
            height[lh]<=height[rh] ? lh++ :rh--;



        }
        return mx;
    }
};