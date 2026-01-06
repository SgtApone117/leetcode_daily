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
    int levelOfTree(TreeNode* root) //recursion
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftLevel  = levelOfTree(root->left); 
        int rightLevel = levelOfTree(root->right);
        return 1 + max(leftLevel,rightLevel);
    }    

    int levelOfTreeQueue(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            level = level + 1;

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        return level;
    }

    int sumAtEachLevel(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        pair<int,int> res = make_pair(1,root->val);
        //vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            level = 1 + level;
            int sum = 0;

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                sum = sum + node->val;
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
                
            }
            if(res.second < sum)
            {
                res.first = level;
                res.second = sum;
            }
            //result.push_back(sum);
        }
        return res.first;
    }
public:
    int maxLevelSum(TreeNode* root) {
        return sumAtEachLevel(root);
    }
};