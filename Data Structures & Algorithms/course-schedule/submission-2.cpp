class Solution {
public:
    bool dfs(int i, vector<bool>& vis, vector<vector<int>>& adj, 
             vector<bool>& pathRec){
        vis[i]=true;
        pathRec[i]=true;
        for(int nbor:adj[i]){
            if(!vis[nbor]){
                if(dfs(nbor, vis, adj, pathRec)){
                    return true;
                }
            }else if(pathRec[nbor]){
                return true;
            }
        }
        pathRec[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(vector<int> edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);
        vector<bool> pathRec(n, false);
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(dfs(i,vis,adj, pathRec)==true){
                    return false;
                }
            }
        }
        return true;
    }
};
