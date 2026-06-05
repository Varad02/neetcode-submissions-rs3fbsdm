class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto i: asteroids) {
            if (st.empty() or st.top() < 0 or (st.top() > 0 and i > 0)) {
                st.push(i);
                continue;
            }
            if (st.top() == abs(i)) {
                st.pop();
                continue;
            }
            while (!st.empty() and st.top() < abs(i) and st.top() > 0) st.pop();
            if (!st.empty() && st.top() == abs(i)) {
                st.pop();
            } else if (st.empty() || st.top() < 0) {
                st.push(i);
}
        }
        vector<int> arr;
        while (!st.empty()) {
            arr.push_back(st.top());
            st.pop();
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};