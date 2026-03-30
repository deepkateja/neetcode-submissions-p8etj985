class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=arr.size()-1;i>=0;i--){
            if(s.empty()){
                s.push({arr[i],i});
                ans.push_back(0);
            }else{
                while(!s.empty() && s.top().first<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push({arr[i],i});
                    ans.push_back(0);
                }else{
                    ans.push_back(s.top().second-i);
                    s.push({arr[i],i});
                }
            }   
            // cout << "i = " << i << " and stack size = " << s.size() << endl;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }   
};
