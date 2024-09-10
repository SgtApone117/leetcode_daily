/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head; 
        ListNode *previous,*current, *nextNode;
        nextNode = head->next;
        current = head;
        while(current && nextNode)
        {
            ListNode *temp = new ListNode;
            temp->val = __gcd(current->val, nextNode->val);
            temp->next = current->next;
            current->next = temp;
            current = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};