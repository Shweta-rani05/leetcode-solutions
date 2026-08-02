class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> res;

        // First window
        for(int i = 0; i < k; i++) {

            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
        }

        // Remaining windows
        for(int i = k; i < nums.size(); i++) {

            // Maximum of previous window
            res.push_back(nums[dq.front()]);

            // Remove indices out of current window
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
        }

        // Last window
        res.push_back(nums[dq.front()]);

        return res;
    }
};