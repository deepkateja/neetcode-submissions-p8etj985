class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
      int cnt = 0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            cnt++;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                       cnt++;
                        continue;
                    }
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]){
                       cnt++;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return cnt;
     
    }
};
