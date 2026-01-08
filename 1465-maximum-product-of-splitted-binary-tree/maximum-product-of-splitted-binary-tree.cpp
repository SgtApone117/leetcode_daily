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
    using LL = long long;
    LL totalSum = 0;
    int MOD = 1e9+7;
    LL maxProd = 0;
    LL getTotalSum(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }
    LL solve(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        LL subTree = root->val + solve(root->left) + solve(root->right);
        maxProd = max(maxProd, subTree * (totalSum - subTree));
        return subTree;
    }
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        solve(root);
        return (maxProd % MOD);
    }
};