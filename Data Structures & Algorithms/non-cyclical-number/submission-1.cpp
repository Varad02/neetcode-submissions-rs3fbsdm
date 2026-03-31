class Solution {
public:
    int sumOfSquares(int n) {
        int sum = 0;
        
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {        
        unordered_set<int> seen;

        while (seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumOfSquares(n);

            if (n == 1) 
                return true;
        }

        return false;
    }
};
