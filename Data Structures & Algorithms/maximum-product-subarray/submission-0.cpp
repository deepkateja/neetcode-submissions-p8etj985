class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // cout << "starting" << endl;
        int n = nums.size();
        int maxu = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(n,INT_MIN));
        // cout << "reached here" << endl;
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                // cout << i <<" " << j << endl;
                if(len==1){
                    dp[i][j]=nums[i];
                }else if(len==2){ 
                    dp[i][j] = nums[i]*nums[j];
                }else{
                    dp[i][j]=nums[i]*dp[i+1][j-1]*nums[j];
                }
                 maxu = max(maxu, dp[i][j]);
            }
        }
        return maxu;
    }
};
