class Solution {
public:
    void recurse(set<vector<int>>& preans, vector<int> nums, int target, int curr, vector<int> currv){
        if(curr==target){
            sort(currv.begin(),currv.end());
            preans.insert(currv);
            return;
        }
        if(curr>target){
            return;
        }
        for(int i:nums){
            curr+=i;
            currv.push_back(i);
            recurse(preans, nums, target, curr, currv);
            curr-=i;
            currv.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> preans;
        recurse(preans, nums, target, 0, {});
        vector<vector<int>> ans;
        for(auto it: preans){
            ans.push_back(it);
        }
        return ans;
    }
};
