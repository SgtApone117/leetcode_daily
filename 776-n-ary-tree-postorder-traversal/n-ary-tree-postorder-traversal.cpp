/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    void traverse(Node* root)
    {
        if(!root)
            return;
        for(auto& child : root->children)
        {
            traverse(child);
        }
        result.push_back(root->val);
        
    }
    vector<int> postorder(Node* root) 
    {
        result.clear();
        traverse(root);
        return result;      
    }
};