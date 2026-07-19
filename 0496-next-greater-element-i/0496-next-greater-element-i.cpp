class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();
        vector<int> ans(n);
        stack<int> s;

        // Next Greater for nums2
        for (int i = n - 1; i >= 0; i--) {

            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            if (s.empty())
                ans[i] = -1;
            else
                ans[i] = s.top();

            s.push(nums2[i]);
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = ans[i];
        }

        vector<int> res;
        for (int x : nums1) {
            res.push_back(mp[x]);
        }

        return res;
    }
};