class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<pair<int,int>> s;
        for(int i=0;i<heights.size();i++){
            int start = i;
            while(!s.empty() && s.top().second>heights[i]){
                pair<int,int> p = s.top();
                s.pop();
                int h = p.second;
                int index = p.first;
                ans = max(ans, h*(i-index));
                start = index;
            }
            s.push({start, heights[i]});
        }
        int n = heights.size();
        while(!s.empty()){
            pair<int,int> p = s.top();
            s.pop();
            ans= max(ans, p.second*(n-p.first));
        }
        return ans;
    }
};
