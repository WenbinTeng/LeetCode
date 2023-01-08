#include <stack>

class MinStack {
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        valStack.push(val);
        minStack.push(std::min(minStack.top(), val));
    }
    
    void pop() {
        valStack.pop();
        minStack.pop();
    }
    
    int top() {
        return valStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> valStack;
    std::stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */