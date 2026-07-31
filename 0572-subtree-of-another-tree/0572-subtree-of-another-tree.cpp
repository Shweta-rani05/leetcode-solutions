class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return p == q;   // true only if both are NULL
        }
        return p->val == q->val
            && isIdentical(p->left, q->left)
            && isIdentical(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == NULL) return true;   // empty tree is always a subtree
        if (root == NULL) return false;     // subRoot non-null but root exhausted

        if (root->val == subRoot->val && isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};