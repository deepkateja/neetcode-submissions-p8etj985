class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size(), m = grid[0].size();
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
        return;
    }
};
