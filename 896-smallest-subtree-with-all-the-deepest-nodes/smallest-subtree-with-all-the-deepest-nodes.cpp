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
    pair<TreeNode*, int> solve(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {nullptr, 0};
        }
        auto leftNode = solve(root->left);
        auto rightNode = solve(root->right);

        if(leftNode.second > rightNode.second)
        {
            return {leftNode.first, leftNode.second+1};
        }

        if(rightNode.second > leftNode.second)
        {
            return {rightNode.first, rightNode.second+1};
        }

        return {root,leftNode.second+1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).first;
    }
};