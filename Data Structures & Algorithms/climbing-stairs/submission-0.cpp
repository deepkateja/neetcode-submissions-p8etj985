class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)return n;
        int one = 1, two = 2;
        int ans;
        for(int i=3;i<=n;i++){
           int three = one+two;
           one = two;
           two = three;
        }
        return two;
    }
};
