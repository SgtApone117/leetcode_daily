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
    int result = 0;
    
    void solve(TreeNode* root, vector<int>& temp) {
        if(root != NULL) {
            temp[root->val]++;
            
            if(root->left == NULL && root->right == NULL) {
                int oddFreq = 0;
                for(int i = 1; i <= 9; i++) {
                    if(temp[i]%2 != 0) {
                        oddFreq++;
                    }
                }

                result += oddFreq <= 1;
            }
            
            
            solve(root->left, temp);
            solve(root->right, temp);
            
            temp[root->val]--;

        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> temp(10, 0);
        
        solve(root, temp);
        return result;
    }
};