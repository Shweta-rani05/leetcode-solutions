class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        int cnt = 0;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            if (cnt % 2 != 0)
                reverse(level.begin(), level.end());

            result.push_back(level);

            cnt++;
        }

        return result;
    }
};