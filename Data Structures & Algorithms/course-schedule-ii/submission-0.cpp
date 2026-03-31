class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);
        for(auto edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);
            degree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        vector<bool> vis(n,false);
        while(!q.empty()){
            int a = q.front();
            q.pop();
            vis[a] = true;
            ans.push_back(a);
            for(int i:adj[a]){
                if(vis[i]==false){
                    degree[i]--;
                    if(degree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        if(ans.size()!=n){
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
