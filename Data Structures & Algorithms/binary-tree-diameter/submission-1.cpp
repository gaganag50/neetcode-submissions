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
    pair<int,int> helper(TreeNode* root) {
        if(!root) return {0,0};
        auto L = helper(root->left);
        auto R = helper(root->right);
        return {
                    1 + max(L.first, R.first),
                    max(max(L.second, R.second), L.first+ R.first)

            };

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};
