class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '(' or c == '{' or c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;
                if (c == ')') {
                    if (st.top() != '(') return false;
                    st.pop();
                } else if (c == '}') {
                    if (st.top() != '{') return false;
                    st.pop();
                }
                if (c == ']') {
                    if (st.top() != '[') return false;
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
