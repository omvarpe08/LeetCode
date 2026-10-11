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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* temp1 = even;

        while(odd->next != NULL || even != NULL) {
            odd->next = odd->next->next;
            if(odd->next != NULL) {
                even->next = odd->next->next;
                odd = odd->next;
            }
            even = odd->next; 
        }

        odd->next = temp1;

        return head;
    }
};