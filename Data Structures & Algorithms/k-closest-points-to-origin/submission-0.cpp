class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i = 0;i<points.size();i++){
            vector<int> point = points[i];
            int a = point[0],  b= point[1];
            pq.push({a*a+b*b,i});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};
