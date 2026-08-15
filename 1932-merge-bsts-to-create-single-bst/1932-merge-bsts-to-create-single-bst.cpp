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
    unordered_map<int, TreeNode*> mp;
    int used = 0;

    bool dfs(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        // BST validation
        if (root->val <= low || root->val >= high)
            return false;

        // If root is a leaf, try to merge another BST here
        if (!root->left && !root->right) {
            if (mp.count(root->val)) {
                TreeNode* tree = mp[root->val];

                root->left = tree->left;
                root->right = tree->right;

                mp.erase(root->val);
                used++;
            }
        }

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        // Store all tree roots
        for (TreeNode* tree : trees) {
            mp[tree->val] = tree;
        }

        // Find the root of the final tree.
        // A final root cannot be the leaf/root value of another tree.
        unordered_set<int> childValues;

        for (TreeNode* tree : trees) {
            if (tree->left)
                childValues.insert(tree->left->val);

            if (tree->right)
                childValues.insert(tree->right->val);
        }

        TreeNode* root = nullptr;

        for (TreeNode* tree : trees) {
            if (!childValues.count(tree->val)) {
                root = tree;
                break;
            }
        }

        if (!root) return nullptr;

        // Remove final root from map
        mp.erase(root->val);

        // Number of trees already included
        used = 1;

        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;

        // Every tree must have been merged
        if (used != trees.size())
            return nullptr;

        return root;
    }
};