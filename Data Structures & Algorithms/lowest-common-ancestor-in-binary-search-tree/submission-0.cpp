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
    bool find(TreeNode* root, TreeNode* target){
        if(!root)return false;
        if(root==target)return true;
        return find(root->left, target)||find(root->right, target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)return root;
        bool fpl = find(root->left, p);
        bool fpr = find(root->right, p);
        bool fql = find(root->left, q);
        bool fqr = find(root->right, q);
        if(fpl && fql)return lowestCommonAncestor(root->left, p, q);
        if(fpr && fqr)return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
