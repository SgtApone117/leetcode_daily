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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int dir = 0;

        int top   = 0;
        int down  = m-1;

        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right)
        {
            if(0 == dir)
            {
                for(int i = left; head != NULL && i <= right; i++)
                {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }
            else if(1 == dir)
            {
                for(int i = top; head != NULL && i <= down; i++)
                {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }
            else if(2 == dir)
            {
                for(int i = right; head != NULL && i >= left; i--)
                {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }
            else
            {
                for(int i = down; head != NULL && i >= top; i--)
                {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;
    }
};