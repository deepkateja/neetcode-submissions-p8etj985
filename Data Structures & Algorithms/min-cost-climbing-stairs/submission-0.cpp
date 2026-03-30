class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int one = cost[0], two = cost[1];
        for(int i=2;i<n;i++){
            int three = min(two+cost[i],one+cost[i]);
            one = two;
            two = three;
        }
        return min(one, two);
    }
};
