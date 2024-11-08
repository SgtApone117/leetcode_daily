class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> result(n);

        int mask = ((1 << maximumBit) - 1);
        int XOR = 0;
        for(int &num : nums)
        {
            XOR ^= num;
        }

        for(int i = 0; i < n; i++)
        {
            int ans = XOR^mask;
            result[i] = ans;

            XOR = (XOR^nums[n-i-1]);
        }
        return result;
    }
};