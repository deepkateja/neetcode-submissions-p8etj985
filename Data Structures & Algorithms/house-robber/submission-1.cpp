class Solution {
public:
    int rob(vector<int>& cost) {
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
};
