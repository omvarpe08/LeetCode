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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int sum;
        int num;
        int rem = 0;
        ListNode* head = nullptr;
        ListNode* temp = nullptr;

        while (temp1 != NULL && temp2 != NULL) {
            sum = temp1->val + temp2->val + rem;
            num = sum % 10;
            rem = sum / 10;

            if (head == nullptr) {
                ListNode* newNode = new ListNode(num);
                head = newNode;
                temp = head;
                temp1 = temp1->next;
                temp2 = temp2->next;
                continue;
            }
            if (head == nullptr)
                return head;

            ListNode* newNode = new ListNode(num);
            temp->next = newNode;
            temp = temp->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != NULL) {
            sum = temp1->val + rem;
            num = sum % 10;
            rem = sum / 10;

            ListNode* newNode = new ListNode(num);
            temp->next = newNode;
            temp = temp->next;

            temp1 = temp1->next;
        }

        while(temp2 != NULL) {
            sum = temp2->val + rem;
            num = sum % 10;
            rem = sum / 10;

            ListNode* newNode = new ListNode(num);
            temp->next = newNode;
            temp = temp->next;

            temp2 = temp2->next;
        }

        if(rem != 0) {
            ListNode* newNode = new ListNode(rem);
            temp->next = newNode;
            newNode = nullptr;
        }
        else {
            temp->next = nullptr;
        }

        return head;
    }
};