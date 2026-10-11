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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int target = cnt - n;

        if(target == 0) {
            head = head->next;
            return head;
        }

        cnt = 0;
        ListNode* temp1 = head;

        while(temp1 != NULL) {
            cnt++;

            if(cnt == target) {
                ListNode* tar = temp1->next;
                temp1->next = temp1->next->next; 
                delete tar;
                break;
            }

            temp1 = temp1->next;
        }

        return head;
    }
};