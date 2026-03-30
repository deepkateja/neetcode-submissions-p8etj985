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
    void recurse(vector<int>& ans, TreeNode* root, int val){
        if(!root)return;
        if(val<=root->val){
            ans.push_back(root->val);
        }
        val = max(root->val, val);
        recurse(ans,root->left, val);
        recurse(ans, root->right, val);
    }
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        vector<int> ans;
        ans.push_back(root->val);
        recurse(ans,root->left, root->val);
        recurse(ans, root->right, root->val);
        return ans.size();
    }
};
