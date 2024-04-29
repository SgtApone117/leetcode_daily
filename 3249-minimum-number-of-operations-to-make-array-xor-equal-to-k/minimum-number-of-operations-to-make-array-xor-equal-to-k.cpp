class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalXor = 0;
        for(int &num : nums)
        {
            totalXor ^= num;
        }
        totalXor = (totalXor ^ k);
        return __builtin_popcount(totalXor);
    }
};