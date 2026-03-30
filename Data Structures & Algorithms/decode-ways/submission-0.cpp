class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n,0);
        if(s[0]=='0'){
            return 0;
        }
        if(s[0]!='0'){
            dp[0]=1;
        }
        if(n==1){
            return dp[0];
        }
        int val = (s[0]-'0')*10 + s[1]-'0';
        if(val>=1&&val<=26 &&s[0]!='0'){
            if(s[1]!='0'){

            dp[1]=2;
            }else{
                dp[1]=1;
            }
        }else{
            if(s[1]!='0'){
                 dp[1]=1;
            }else{
                dp[1]=0;
            } 
        }
        for(int i=2;i<n;i++){
            if(s[i]!='0'){
                dp[i]+=dp[i-1];;
            }
            if(i>=2 && s[i-1]!='0'){
                int num = (s[i-1]-'0')*10 + s[i]-'0';
                if(num>=1&&num<=26){
                    dp[i]+=dp[i-2];
                }
            }
        }
        for(int i:dp){
            cout << i << " ";
        }
        cout << endl;
        return dp[n-1];
    }
};
