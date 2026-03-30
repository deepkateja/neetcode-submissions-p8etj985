class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0)return n;
        unordered_map<char,int> mp;
        int start = 0;
        mp[s[0]] = 0;
        int ans = 1;
        for(int i = 1;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                // cout << "for i here " << i << endl; 
                mp[s[i]]=i;
                ans = max(ans, i-start+1);
            }else{
                // cout << mp[i] << " " << start << endl;
                if(mp[s[i]]<start){
                    // cout << "for i here1 " << i << endl; 

                    mp[s[i]]=i;
                    ans = max(ans, i-start+1);
                }else{
                    // cout << "for i here2 " << i << endl; 
                    start = mp[s[i]]+1;
                    mp[s[i]] = i;
                    ans = max(ans, i-start+1);
                }
            }
            // cout << "for i = " << i << " ans is " << ans << " and start is " << start << endl;
        }
        return ans;
    }
};
