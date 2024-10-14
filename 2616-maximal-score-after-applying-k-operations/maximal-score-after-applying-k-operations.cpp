class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for (int i = 0; i < nums.size(); ++i) {
            max_heap.push(nums[i]);
        }
        long long ans = 0;
        while (k--) {
            int num = max_heap.top();
            max_heap.pop();
            ans += num;
            num = ceil(num / 3.0);
            max_heap.push(num);
        }
        return ans;
    }
};