/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class HeapNode {
public:
    int val;
    int lIdx;

    HeapNode(int val, int lIdx) {
        this->val = val;
        this-> lIdx = lIdx;
    }

    bool operator < (const HeapNode &a) const
    {
        return val > a.val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<HeapNode> h;
        int nonemptyQ = lists.size();
        ListNode* ret = new ListNode(0);
        ListNode* nowNode = ret;

        if (lists.size() == 0) {
            return NULL;
        }

        for(int lIdx = 0; lIdx < lists.size(); ++lIdx) {
            if (lists[lIdx]) {
                HeapNode hNode = HeapNode(lists[lIdx]->val, lIdx);
                h.push(hNode);
                lists[lIdx] = lists[lIdx]->next;
            } else {
                nonemptyQ -= 1;
            }
        }

        while (nonemptyQ) {
            HeapNode topNode = h.top();
            h.pop();
            nowNode->next = new ListNode(topNode.val);
            nowNode = nowNode->next;
            if (lists[topNode.lIdx]) {
                h.push(HeapNode(lists[topNode.lIdx]->val, topNode.lIdx));
                lists[topNode.lIdx] = lists[topNode.lIdx]->next;
            } else {
                nonemptyQ -= 1;
            }
        }

        return ret->next;
    }
};