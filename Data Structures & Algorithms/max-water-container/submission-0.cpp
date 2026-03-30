class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size()-1;
        int ans = 0;
        while(i<=j){
            ans = max(ans, min(heights[j],heights[i])*(j-i));
            if(heights[j]<heights[i]){
                j--;
            }else{
                i++;
            }
        }
        return ans;
    }
};
