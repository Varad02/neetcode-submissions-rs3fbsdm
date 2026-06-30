class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1, n2, c1 = 0, c2 = 0;
        for (auto i : nums) {
            if (i == n1) {
                c1++;
            } else if (i == n2) {
                c2++;
            } else if (c1 == 0) {
                n1 = i;
                c1++;
            } else if (c2 == 0) {
                n2 = i;
                c2++;
            } else {
                c1--;
                c2--;
            }
        }
        vector<int> res;
        int count1 = 0;
        int count2 = 0;
        for (const int num : nums) {
            if (num == n1) {
                count1++;
            } else if (num == n2) {
                count2++;
            }
        }
        cout << count1;
        if (count1 > nums.size() / 3) {
            res.push_back(n1);
        }
        if (count2 > nums.size() / 3) {
            res.push_back(n2);
        }

        return res;
    }
};