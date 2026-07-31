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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode* > s;
        TreeNode* curr = root ;
        while(curr != NULL || !s.empty()){
            while(curr != NULL){
                 s.push(curr);//stack m curr ki value push ki 
                 curr = curr->left; // curr m left ki value push ki 

            }
            curr = s.top(); // curr m stack ka top store kraya 
            s.pop(); // top element pop kr liya 
            result.push_back(curr->val); // result m push_back kr diya curr ki value ko 
            curr = curr ->right ;//curr ko right m increment kr diya 
        }
        return result ;
    }
};