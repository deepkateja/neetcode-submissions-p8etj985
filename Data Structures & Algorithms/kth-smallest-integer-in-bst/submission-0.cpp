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
    int cnt(TreeNode* root){
        if(!root)return 0;
        return cnt(root->left)+cnt(root->right)+1;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return 0;
        int leftCount = cnt(root->left);
        if(leftCount==k-1){
            return root->val;
        }
        if(leftCount >= k){
            return kthSmallest(root->left, k);
        }
        return kthSmallest(root->right, k-leftCount-1);
    }
};
