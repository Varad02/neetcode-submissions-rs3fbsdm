class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int result;
        for(const auto& token : tokens){
            if(token == "+" || token == "*" || token == "-" || token == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                if( token == "+"){
                    result = b + a;
                    stk.push(result);
                }
                else if(token == "-"){
                    result = b - a;
                    stk.push(result);
                }
                else if(token == "/"){             
                    result = b / a;
                    stk.push(result);
                }
                else if(token == "*"){
                    result = b * a;
                    stk.push(result);
                }
            }else stk.push(stoi(token));
            
        }
        return stk.top();
    }
};
