/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        while(temp != nullptr)
        {
            Node *copy_node = new Node(temp->val);
            copy_node->next = temp->next;
            temp->next = copy_node;
            temp = temp->next->next;
        }
        temp = head;
        while(temp != nullptr)
        {
            Node *copy_node = temp->next;
            copy_node->random = (temp->random != nullptr) ? temp->random->next : nullptr;
            temp = temp->next->next;
        }
        temp = head;
        Node *dummy_node = new Node(-1);
        Node *res = dummy_node;
        while(temp != nullptr)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummy_node->next;
    }
};