class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        priority_queue<pair<int,int>> maxHeap;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        int j = 0;
        for (int i = k; i < nums.size(); i++) {
            while (maxHeap.top().second < j) {
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
            maxHeap.push({nums[i], i});
            j++;
        }
        while (maxHeap.top().second < j) {
            maxHeap.pop();
        }
        ans.push_back(maxHeap.top().first);
        return ans;
    }
};
