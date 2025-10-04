#include <stack>

class MinStack {
  public:
    MinStack() { minStack.push(INT_MAX); }

    void push(int val) {
        valStack.push(val);
        if (val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        auto top = valStack.top();
        if (top == minStack.top()) {
            minStack.pop();
        }
        valStack.pop();
    }

    int top() { return valStack.top(); }

    int getMin() { return minStack.top(); }

  private:
    std::stack<int> minStack;
    std::stack<int> valStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */