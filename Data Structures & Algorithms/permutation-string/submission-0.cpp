class Solution {
public:
    bool areSame(vector<int>& v1, vector<int>& v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> s1f(26,0);
        int n = s1.size(),m=s2.size();
        if(n>m){
            return false;
        }
        for(char c:s1){
            s1f[c-'a']++;
        }
        vector<int> s2f(26,0);
        for(int i=0;i<n;i++){
            s2f[s2[i]-'a']++;
        }
        if(areSame(s1f,s2f)){
            return true;
        }
        for(int j=n;j<m;j++){
            s2f[s2[j-n]-'a']--;
            s2f[s2[j]-'a']++;
            if(areSame(s1f,s2f)){
                return true;
            }
        }
        return false;

    }
};
