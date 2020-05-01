/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* retListBef = new ListNode(0);
        ListNode* nowNode = retListBef;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode* tmp = new ListNode(l1->val);
                nowNode->next = tmp;
                nowNode = tmp;
                l1 = l1->next;
            } else {
                ListNode* tmp = new ListNode(l2->val);
                nowNode->next = tmp;
                nowNode = tmp;
                l2 = l2->next;
            }
        }

        while (l1) {
            ListNode* tmp = new ListNode(l1->val);
            nowNode->next = tmp;
            nowNode = tmp;
            l1 = l1->next;
        }

        while (l2) {
            ListNode* tmp = new ListNode(l2->val);
            nowNode->next = tmp;
            nowNode = tmp;
            l2 = l2->next;
        }

        return retListBef->next;
    }
};