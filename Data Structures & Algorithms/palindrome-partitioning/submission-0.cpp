class Solution {
public:
    void recurse(string& s, vector<string>& curr, int ind, vector<vector<string>>& res, 
    vector<vector<bool>>& dp){
        if(ind == s.size()){
            res.push_back(curr);
            return;
        }
        string temp;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(dp[ind][i]){
                curr.push_back(temp);
                recurse(s,curr, i+1, res, dp);
                curr.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(len==1){
                    dp[i][j]=true;
                }else if(len==2){
                    dp[i][j]= (s[i]==s[j])?true:false;
                }else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        vector<vector<string>> res;
        vector<string> curr;
        recurse(s,curr,0, res, dp);
        return res;
    }
};
