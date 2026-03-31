class Solution {
public:
    int orangesRotting(vector<vector<int>>& input) {
         queue<pair<int,pair<int,int>>> q;
        int n = input.size(), m = input[0].size();
        vector<vector<int>> grid(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(input[i][j]==0){
                    grid[i][j]=-1;
                }else if(input[i][j]==1){
                    grid[i][j]=INT_MAX;
                }else{
                    grid[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int x = p.second.first;
            int y = p.second.second;
            int dist = p.first;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]!=INT_MAX){
                    continue;
                }
                grid[nx][ny]=dist+1;
                q.push({dist+1,{nx,ny}});
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==INT_MAX){
                    return -1;
                }
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};
