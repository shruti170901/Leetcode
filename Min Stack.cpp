// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> stk;
    MinStack() {
        while(!stk.empty()) stk.pop();
    }
    
    void push(int x) {
        if(stk.empty() || stk.top().second>=x) stk.push({x, x});
        else stk.push({x, stk.top().second});
    }
    
    void pop() {
        if(!stk.empty()) stk.pop();
    }
    
    int top() {
        if(!stk.empty()) return stk.top().first;
        return -1;
    }
    
    int getMin() {
        if(!stk.empty()) return stk.top().second;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */