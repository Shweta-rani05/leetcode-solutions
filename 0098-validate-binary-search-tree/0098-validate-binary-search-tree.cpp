/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, TreeNode* max,TreeNode*  min) {
        if(root == NULL) return true;

        if(min != NULL && root ->val <= min->val){
            return false;
        }

        if(max != NULL && root ->val >= max->val){
            return false;
        }

       return helper(root->left, root, min) && helper(root->right, max, root);
    }

    bool isValidBST(TreeNode* root){
        return helper(root,NULL,NULL);
    }
};