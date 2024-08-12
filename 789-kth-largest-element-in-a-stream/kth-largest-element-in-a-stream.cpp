class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth_val;
public:
    KthLargest(int k, vector<int>& nums) : kth_val(k) {
        for(int& num : nums)
        {
            add(num);
        }
    }
    
    int add(int val) {
        if(minHeap.size() < kth_val)
        {
            minHeap.push(val);
        }
        else if(val > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */