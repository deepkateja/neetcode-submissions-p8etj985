class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax, rmax;
       
        int lmaxyet = 0;
        for(int i:height){
            lmax.push_back(lmaxyet);
            lmaxyet = max(lmaxyet, i);
        }
        lmaxyet = 0;
        for(int i=height.size()-1;i>=0;i--){
            rmax.push_back(lmaxyet);
            lmaxyet = max(lmaxyet, height[i]);
        }
        reverse(rmax.begin(),rmax.end());
        int ans = 0;
        for(int i=0;i<height.size();i++){
            if(height[i]<min(lmax[i],rmax[i])){
                ans+=min(lmax[i],rmax[i])-height[i];
            }
        }
        return ans;
    }
};
