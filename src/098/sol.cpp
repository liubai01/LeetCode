/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Ret {
    int treeMax;
    int treeMin;
    bool isBST;
    Ret(int x, int y, bool z) : treeMax(x), treeMin(y), isBST(z) {}
};

class Solution {
public:
    struct Ret isValidBSTRec(TreeNode* root) {
        struct Ret ret(root->val, root->val, true);
        if (root->left) {
            struct Ret retLeft = isValidBSTRec(root->left);
            if (!retLeft.isBST) {
                ret.isBST = false;
                return ret;
            }
            if (retLeft.treeMax >= root->val) {
                ret.isBST = false;
                return ret;
            }
            ret.treeMin = retLeft.treeMin;
        }

        if (root->right) {
            struct Ret retRight = isValidBSTRec(root->right);
            if (!retRight.isBST) {
                ret.isBST = false;
                return ret;
            }
            if (retRight.treeMin <= root->val) {
                ret.isBST = false;
                return ret;
            }
            ret.treeMax = retRight.treeMax;
        }

        return ret;
    }

    bool isValidBST(TreeNode* root) {
        if (root) {
            struct Ret ret = isValidBSTRec(root);
            return ret.isBST;
        }
        return true;
    }
};