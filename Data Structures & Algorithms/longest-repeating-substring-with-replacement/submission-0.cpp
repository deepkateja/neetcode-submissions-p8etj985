class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int fre = 0, ans = 0;
        for(int i=0;i<s.size();i++){
            fre = max(fre,++mp[s[i]]);
            if(ans-fre<k){
                ans++;
            }else{
                mp[s[i-ans]]--;
            }
        }
        return ans;
    }
};
