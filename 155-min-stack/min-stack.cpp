class MinStack {
    int top_;
    MinStack* prev;
    int minEle;
public:
    MinStack() {
        top_ = -1;
        prev = nullptr;
        minEle = INT_MAX;
    }
    
    void push(int val) {
        MinStack* currNode = new MinStack();
        currNode->top_ = top_;
        currNode->minEle = minEle;
        currNode->prev = prev;
        top_ = val;
        minEle = min(val, currNode->minEle);
        prev = currNode;
    }
    
    void pop() {
        if(prev != nullptr)
        {
            top_ = prev->top_;
            minEle = prev->minEle;
            prev = prev->prev;
        }
    }
    
    int top() {
        return top_;
        
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */