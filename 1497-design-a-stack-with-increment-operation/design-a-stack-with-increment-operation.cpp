class CustomStack {
private:
    vector<int> st;
    int maxSize;
    int size;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        size = 0;
    }
    
    void push(int x) {
        if(size < maxSize)
        {
            st.push_back(x);
            size++;
        }
    }
    
    int pop() {
        if(size <= 0)
            return -1;
        size--;
        int x = st[size];
        st.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k,size); i++)
        {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */