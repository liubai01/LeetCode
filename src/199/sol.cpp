/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recursiveDFS(vector<int> &retSeq, TreeNode* root, int depth) {
        if (retSeq.size() <= depth) {
            retSeq.push_back(root->val);
        }
        if (root->right) {
            recursiveDFS(retSeq, root->right, depth + 1);
        }
        if (root->left) {
            recursiveDFS(retSeq, root->left, depth + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> retSeq;
        retSeq.clear();
        if (root) {
            recursiveDFS(retSeq, root, 0);
        }
        
        return retSeq;
    }
};