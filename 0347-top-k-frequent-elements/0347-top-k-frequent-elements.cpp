class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min heap
        // pair = {frequency, number}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Step 3: Keep k most frequent elements
        for (auto& it : freq) {
            int num = it.first;
            int count = it.second;

            pq.push({count, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract answer
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};