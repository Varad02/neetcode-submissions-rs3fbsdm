class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (true) {
            int ans = util (n);
            if (ans == 1) {
                return true;
            }
            if (m[ans]!=0) {
                return false;
            }
            else {
                m[ans] = 1;
                n = ans;
            }
        }
        return true;
    }

    int util (int n) {
        int ans = 0;
        while (n>0) {
            ans+= (n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
};
