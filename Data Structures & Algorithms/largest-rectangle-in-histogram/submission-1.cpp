class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMost(n,-1),rightMost(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()){
                leftMost[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()){
                rightMost[i] = st.top();
            }
            st.push(i);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            ans = max(ans,(rightMost[i]-leftMost[i]-1)*heights[i]);
        }
        return ans;
    }
};
