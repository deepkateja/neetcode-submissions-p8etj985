class Solution {
public:
 int robbefore(vector<int>& cost) {
         int n = cost.size();
         if(n==1){
            return cost[0];
         }
        int one = cost[0], two = max(cost[0], cost[1]);
        for(int i=2;i<n;i++){
            int three = max(two,one+cost[i]);
            one = two;
            two = three;
        }
        return max(one, two);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> nums2(nums.begin()+1, nums.end());
        vector<int> nums3(nums.begin(), nums.end()-1);
        return max(robbefore(nums2), robbefore(nums3));
    }
};
