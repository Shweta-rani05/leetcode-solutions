class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) return ""; // If the array is empty, return an empty string.
            string prefix = strs[0]; // Initialize the prefix as the first string.
             for (int i = 1; i < strs.size(); i++) {
                while (strs[i].find(prefix) != 0) {
                     prefix = prefix.substr(0, prefix.size() - 1); // Remove the last character from the prefix.
                   if (prefix.empty()) return ""; // If the prefix becomes empty, return an empty string.
                }
             }        
            return prefix ;
        }
};