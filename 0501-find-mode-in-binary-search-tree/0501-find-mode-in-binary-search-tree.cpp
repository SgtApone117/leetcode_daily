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
    void inOrderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
        {
            return;
        }
        inOrderTraversal(root->left,inorder);
        inorder.emplace_back(root->val);
        inOrderTraversal(root->right, inorder);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> inorder;
        if(root == NULL)
        {
            return inorder;
        }
        if(root->right == NULL && root->left == NULL)
        {
            inorder.emplace_back(root->val);
            return inorder;
        }
        inOrderTraversal(root, inorder);
        int mx =INT_MIN;
        unordered_map<int,int> mp;
        for(int i = 0; i <  inorder.size(); i++)
        {
            mp[inorder[i]]++;
        }
        vector<int> res;
        for(auto it : mp)
        {
            if(it.second > mx)
            {
                mx = it.second;
            }
        }
        for(auto c : mp)
        {
            if(c.second == mx)
            {
                res.emplace_back(c.first);
            }
        }
        return res;
    }
};