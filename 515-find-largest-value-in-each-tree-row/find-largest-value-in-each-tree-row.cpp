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
    vector<int> result;

    void DFS(TreeNode* root, int depth)
    {
        if(root == NULL)
        {
            return;
        }

        if(depth == result.size())
        {
            result.emplace_back(root->val);
        }
        else
        {
            result[depth] = max(result[depth], root->val);
        }
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }

    vector<int> largestValues(TreeNode* root) {
        DFS(root,0);
        return result;
    }
};