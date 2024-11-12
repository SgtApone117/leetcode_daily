class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int XOR1 = 0;
        int XOR2 = 0;
        int n = nums.size();
        for(int i = 1; i <= n; i++)
        {
            XOR1 ^= i;
        }
        for(int &num : nums)
        {
            XOR2 ^= num;
        }
        return XOR1^XOR2;
    }
};