class MinStack {
public:
    stack<int> arr;
    stack<int> minS;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push(val);
        if (minS.empty() or minS.top() >= val) minS.push(val);
    }
    
    void pop() {
        if (minS.top() == arr.top()) minS.pop();
        arr.pop();
    }
    
    int top() {
        return arr.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
