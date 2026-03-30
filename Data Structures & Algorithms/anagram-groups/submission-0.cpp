class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string s: strs){
            string curr = s;
            sort(curr.begin(),curr.end());
            mp[curr].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
