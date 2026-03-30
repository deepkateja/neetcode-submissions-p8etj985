class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int row=-1;
        for(int i=0;i<n;i++){
            if(target<=matrix[i][m-1] && target>=matrix[i][0]){
                row = i;
                break;
            }
        }
        if(row==-1){
            return false;
        }
        for(int j=0;j<matrix[row].size();j++){
            if(matrix[row][j]==target){
                return true;
            }
        }
        return false;
    }
    
};
