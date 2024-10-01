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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<long int> st;
        vector<int> res;
        long int temp;
        while(root != nullptr || !st.empty())
        {
            if(root != nullptr)
            {
                st.push((long int)root);
                root = root->left;
            }
            else
            {
                temp = st.top();
                st.pop();
                if(temp > 0)
                {
                    st.push(-temp);
                    root = ((TreeNode*)temp)->right;
                }
                else
                {
                    res.push_back(((TreeNode*)(-1 * temp))->val);
                    root = nullptr;
                }
            }
        }
        return res;
    }
};