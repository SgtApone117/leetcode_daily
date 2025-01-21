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

    ListNode* removePrecedingZeroes(ListNode *head)
    {
        while(head != nullptr && head->val == 0)
        {
            head = head->next;
        }
        return head;
    }

    ListNode* reverse_list(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *head_new = reverse_list(head->next);
        ListNode *head_tail = head->next;
        head_tail->next = head;
        head->next = nullptr;
        return head_new;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        //l1 = removePrecedingZeroes(l1);
        //l2 = removePrecedingZeroes(l2);

        // reverse the lists
        //l1 = reverse_list(l1);
        //l2 = reverse_list(l2);
        
        ListNode *sum_node = nullptr;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = 0;
            if(l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;
            ListNode *new_node = new ListNode(sum%10);
            new_node->next = sum_node;
            sum_node = new_node;
        }
        if(sum_node == nullptr)
        {
            ListNode *temp = new ListNode(0);
            temp->next = sum_node;
            sum_node = temp;
        }
        else
            sum_node = reverse_list(sum_node);
        return sum_node;
    }
};