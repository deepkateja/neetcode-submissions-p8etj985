class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxu = 1, start=0, end=0;
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                        start = i;
                        end = j;
                        continue;
                    }
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]){
                        maxu = max(maxu, j-i+1);
                        start = i;
                        end = j;
                    }
                }else{
                    dp[i][j]=false;
                }
            }
        }
        // cout << start << " " 
        string ans = s.substr(start, end-start+1);
        return ans;
    }
};
