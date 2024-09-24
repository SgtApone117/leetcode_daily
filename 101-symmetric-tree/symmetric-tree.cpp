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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* leftTree  = q.front();
            q.pop();
            TreeNode* rightTree = q.front();
            q.pop();
            if(leftTree == nullptr && rightTree == nullptr)
                continue;
            if(leftTree == nullptr || rightTree == nullptr || leftTree->val != rightTree->val)
                return false;
            q.push(leftTree->left);
            q.push(rightTree->right);
            q.push(leftTree->right);
            q.push(rightTree->left);
        }
        return true;
    }
};