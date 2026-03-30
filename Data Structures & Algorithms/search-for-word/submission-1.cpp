class Solution {
public:
    bool dfs(vector<vector<char>>& board, 
             string word,
             int ind, 
             int n,
             int m, 
             vector<vector<bool>>& vis,
             int i, int j){
        
        if(ind==word.size()){
            return true;
        }
        if(i<0 || i>=n ||j<0 ||j>=m){
            return false;
        }
        if(board[i][j]!=word[ind]){
            return false;
        }
        if(vis[i][j]==true){
            return false;
        }
        vis[i][j]=true;
        
        if(dfs(board, word, ind+1, n, m, vis, i+1,j)){
            return true;
        }
        if(dfs(board, word, ind+1, n, m, vis, i-1,j)){
            return true;
        }
        if(dfs(board, word, ind+1, n, m, vis, i,j+1)){
            return true;
        }
        if(dfs(board, word, ind+1, n, m, vis, i,j-1)){
            return true;
        }
       
        vis[i][j]=false;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, 0, n,m, vis, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
