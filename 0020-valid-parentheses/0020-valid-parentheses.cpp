class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c); // Push open brackets onto the stack
            } else {
                if (st.empty()) return false; // No matching open bracket
                
                char top = st.top();
                st.pop();
                
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false; // Mismatched brackets
                }
            }
        }

        return st.empty(); // Ensure no unmatched open brackets remain
    }
};
