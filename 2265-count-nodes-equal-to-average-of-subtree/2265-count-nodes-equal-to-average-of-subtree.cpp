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
    int count = 0;
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
    
private:
    // returns {sum, cnt}
    pair<int,int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto [leftSum, leftCnt] = dfs(node->left);
        auto [rightSum, rightCnt] = dfs(node->right);
        
        int totalSum = leftSum + rightSum + node->val;
        int totalCnt = leftCnt + rightCnt + 1;
        
        if (totalSum / totalCnt == node->val) {
            count++;
        }
        
        return {totalSum, totalCnt};
    }
};