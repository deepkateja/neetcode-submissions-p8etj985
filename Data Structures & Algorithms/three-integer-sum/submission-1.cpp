class Solution {
public:
    void twoSum(int start, int end, vector<int>& nums, set<vector<int>>& ans, int target){
        while(start<end){
            if(nums[start]+nums[end]<target){
                start++;
            }else if(nums[start]+nums[end]>target){
                end--;
            }else{
                ans.insert({nums[start],nums[end],-target});
                if(start+1==end){
                    start++;
                }else{
                    if(nums[start]==nums[start]+1){
                        start++;
                    }else{
                        end--;
                    }
                }
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n<=2){
            return {};
        }
        for(int i=2;i<n;i++){
            int start = 0, end = i-1;
            twoSum(start, end, nums, ans, -nums[i]);
        }
        vector<vector<int>> ansf;
        for(auto s:ans){
            ansf.push_back(s);
        }
        return ansf;
    }
};
