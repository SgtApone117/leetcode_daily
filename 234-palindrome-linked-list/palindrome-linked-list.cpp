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

ListNode *middleNode(ListNode *head)
{
    if(NULL == head)
        return NULL;
    ListNode *slow, *fast;
    slow = fast = head;
    while(fast && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow-> next;
    }
    return slow;
}

ListNode *reverseNode(ListNode *head)
{
    ListNode *previous, *current, *next;
    previous = NULL;
    current = head;
    while(current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode *firstHalf, *secondHalf;
        firstHalf = head;
        secondHalf = middleNode(head);
        secondHalf = reverseNode(secondHalf);
        while(firstHalf && secondHalf)
        {
            if(firstHalf->val != secondHalf->val)
                return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};