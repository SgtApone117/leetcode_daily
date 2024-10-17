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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int size = 0;
        while(curr != nullptr)
        {
            size++;
            curr = curr->next;   
        }
        cout << size << endl;
        int halfList = ceil((double)size/2);
        curr = head;
        while(curr != nullptr && size != halfList)
        {
            size--;
            curr = curr->next;
        }
        return curr;
    }
};