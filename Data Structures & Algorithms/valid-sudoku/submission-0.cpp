class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        set<char> s;
        
        for(int i=0;i<n;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(s.count(board[i][j])){
                        return false;
                    }else{
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            s.clear();
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(s.count(board[j][i])){
                        return false;
                    }else{
                        s.insert(board[j][i]);
                    }
                }
            }
        }
        
        int arr[] = {0,3,6};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                s.clear();
                for(int k=0;k<3;k++){
                    for(int t=0;t<3;t++){
                        if(board[arr[i]+k][arr[j]+t]!='.'){
                            if(s.count(board[arr[i]+k][arr[j]+t])){
                                return false;
                            }else{
                                s.insert(board[arr[i]+k][arr[j]+t]);
                            }
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
