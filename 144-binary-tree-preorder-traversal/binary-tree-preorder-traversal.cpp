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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root != nullptr || !st.empty())
        {
            if(root != nullptr)
            {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return res;
    }
};