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
    int level[1000001];
    int height[1000001];
    int levelMaxHeight[1000001];
    int levelSecondMaxHeight[1000001];

    int Getheight(TreeNode* root, int lvl)
    {
        if(root == nullptr)
            return 0;
        level[root->val] = lvl;
        height[root->val] = max(Getheight(root->left, lvl+1), Getheight(root->right, lvl+1))+1;
        if(levelMaxHeight[lvl] < height[root->val])
        {
            levelSecondMaxHeight[lvl] = levelMaxHeight[lvl];
            levelMaxHeight[lvl] = height[root->val];
        }
        else if(levelSecondMaxHeight[lvl] < height[root->val])
        {
            levelSecondMaxHeight[lvl] = height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        Getheight(root, 0);

        vector<int> result;
        for(int &node : queries)
        {
            int L = level[node];
            int tempResult = L + (levelMaxHeight[L] == height[node] ? levelSecondMaxHeight[L] : levelMaxHeight[L])-1;

            result.push_back(tempResult);
        }
        return result;
    }
};