class Solution {
public:
    void recurse(set<int>& done, vector<vector<int>>& res, 
    vector<int>& curr, vector<int>& nums, int inserted){
        if(inserted==nums.size()){
            res.push_back(curr);
        }
        for(int i=0;i<nums.size();i++){
           if(done.count(i)==0){
                done.insert(i);
                curr.push_back(nums[i]);
                recurse(done, res, curr, nums, inserted+1);
                curr.pop_back();
                done.erase(i);
           }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> done;
        vector<vector<int>> res;
        vector<int> curr;
        recurse(done, res, curr, nums, 0);
        return res;
    }
};
