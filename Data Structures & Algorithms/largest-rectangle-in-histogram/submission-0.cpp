class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        vector<int> nextSmallest(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                nextSmallest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> prevSmallest(n, -1);
        stack<int> st2;
        for (int i = n-1; i > -1; i--) {
            while (!st2.empty() and h[st2.top()] > h[i]) {
                prevSmallest[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, (nextSmallest[i] - prevSmallest[i] - 1) * h[i]);

        return res;
    }
};