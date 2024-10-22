/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long height(TreeNode* root)
    {
        long long x = 0, y =0;
        if(root == nullptr)
            return 0;
        x = height(root->left);
        y = height(root->right);
        return (x>y) ? x+1 : y+1;
    }

    void solve(TreeNode* root, long long level, vector<long long>& calc)
    {
        if(root == nullptr)
            return;
        calc[level] += root->val;
        solve(root->left, level+1, calc);
        solve(root->right, level+1, calc);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        TreeNode* currNode = root;
        long long getHeight = height(root);
        vector<long long> calc(getHeight, 0);
        currNode = root;
        solve(currNode, 0, calc);
        sort(begin(calc), end(calc), greater<long long>());
        if(k > getHeight)
            return -1;
        else
            return calc[k-1];
    }
};