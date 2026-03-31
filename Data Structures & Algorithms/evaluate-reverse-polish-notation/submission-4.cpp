class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ops;
        for (auto i: tokens) {
            if (i == "-" or i == "+" or i == "*" or i == "/") {
                int op1 = ops.top();
                ops.pop();
                int op2 = ops.top();
                ops.pop();
                switch(i[0]) {
                    case '+':
                        ops.push((op1 + op2));
                        break;
                    case '-':
                        ops.push((op2 - op1));
                        break;
                    case '*':
                        ops.push((op1 * op2));
                        break;
                    case '/':
                        ops.push(op2 / op1);
                        break;
                }
            }
            else {
                ops.push(stoi(i));
            }
        }
        return ops.top();
    }
};
