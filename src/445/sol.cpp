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
        vector<int> vec_l1;
        vector<int> vec_l2;
        vector<int> vec_ret;
        int a = 0;
        ListNode* retList = nullptr;
        ListNode* nowNode = nullptr;

        vec_l1.clear();
        vec_l2.clear();

        // push to stack
        while(l1) {
            vec_l1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            vec_l2.push_back(l2->val);
            l2 = l2->next;
        }

        while(true) {
            if (vec_l1.empty() && vec_l2.empty()) {
                break;
            }
            if(!vec_l1.empty()){
                a +=  vec_l1.back();
                vec_l1.pop_back();
            }
            if(!vec_l2.empty()){
                a += vec_l2.back();
                vec_l2.pop_back();
            }
            vec_ret.push_back(a % 10);
            a = a / 10;
        }
        if (a > 0) vec_ret.push_back(a);

        if (vec_ret.empty()) return retList;
        nowNode= new ListNode(vec_ret.back());
        retList = nowNode;
        vec_ret.pop_back();

        while (!vec_ret.empty()){
            ListNode* prevNode = nowNode;
            nowNode = new ListNode(vec_ret.back());
            vec_ret.pop_back();
            prevNode->next = nowNode;
        }
        return retList;
    }
};