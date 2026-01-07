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
    private:
    pair<TreeNode*, TreeNode*> splitTree(TreeNode* parent, bool splitLeft)
    {
        if(parent == nullptr)
        {
            return {nullptr,nullptr};
        }
        TreeNode* detached;
        if(splitLeft)
        {
            detached = parent->left;
            parent->left = nullptr;
        }
        else
        {
            detached = parent->right;
            parent->right = nullptr;
        }
        return {parent, detached};
    }
public:
    int MOD = 1e9+7;
    using LL = long long;
    LL totalSum = 0;
    LL maxProd = 0;
    LL getTotalSum(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    LL dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        LL leftNode = dfs(root->left);
        LL rightNode = dfs(root->right);

        LL subTreeSum = root->val + leftNode + rightNode;
        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return (maxProd % MOD);
    }
};