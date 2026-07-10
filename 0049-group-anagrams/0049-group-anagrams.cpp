class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> mp;

        for (string str : strs) {

            vector<int> freq(26, 0);

            for (char ch : str)
                freq[ch - 'a']++;

            mp[freq].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};