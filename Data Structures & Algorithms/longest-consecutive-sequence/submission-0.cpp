class Solution {
public:
    int calculate(unordered_set<int>& s, int val) {
        int cnt =1 ;
        int currFind  = val+1;
        while(s.find(currFind)!=s.end()) {
            cnt++;
            currFind +=1;
        }
        return cnt;
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        int cnt =0;
        for(int i =0;i<nums.size();i++) {
            if(s.find(nums[i]-1)==s.end())
                cnt = max(cnt,calculate(s, nums[i]));
        }
        return cnt;
    }
};
