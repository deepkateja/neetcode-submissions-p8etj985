/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int findDia(TreeNode* root, bool& ans){
        if(ans == false)return false;
            if(!root)return true;
            int lh = findDia(root->left, ans);
            int rh = findDia(root->right, ans);
            if(lh-rh>1 || lh-rh<-1){
                ans = false;
            }
            return max(lh,rh)+1;
        }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        findDia(root,ans);
        return ans;
    }
};
