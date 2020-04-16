#include <iostream>
#include <string>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* retList = NULL;
        ListNode* prevNode = NULL;
        ListNode* nowNode = NULL;
        int a = 0;

        while (l1 || l2) {
            if (l1 != NULL) {
                a += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                a += l2->val;
                l2 = l2->next;
            }
            nowNode = new ListNode(a % 10);
            a = a / 10;

            if (prevNode != NULL) {
                prevNode->next = nowNode;
            } else {
                retList = nowNode;
            }
            prevNode = nowNode;
        }
        if (a > 0) {
            nowNode = new ListNode(a);
            if (prevNode != NULL) {
                prevNode->next = nowNode;
            } else {
                retList = nowNode;
            }
            prevNode = nowNode;
        }
        return retList;
    }
};