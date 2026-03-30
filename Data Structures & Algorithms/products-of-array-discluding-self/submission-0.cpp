class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right;
        int curr = 1;
        for(int i:nums){
            left.push_back(curr);
            curr*=i;
        }
        curr = 1;
        for(int i=nums.size()-1;i>=0;i--){
            right.push_back(curr);
            curr*=nums[i];
        }
        reverse(right.begin(),right.end());
        // cout << "Lefts are " << endl;
        // for(int i:left){
        //     cout << i << " ";
        // }
        // cout << endl;
        //  for(int i:right){
        //     cout << i << " ";
        // }
        // cout << endl;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};
