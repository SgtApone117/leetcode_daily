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
    int solve(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        pair<int,int> res = {1, root->val};
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            int sum = 0;
            level = level + 1;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            if(res.second < sum)
            {
                res.first = level;
                res.second = sum;
            }
        }
        return res.first;
    }
    int maxLevelSum(TreeNode* root) {
        return solve(root);
    }
};