class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if((n&1) == 0 && (m&1) == 0) return 0;
        if((n&1) == 1 && (m&1) == 0)
        {
            int xor_ = 0;
            for(int& val : nums2)
                xor_ = xor_^val;
            return xor_;
        }
        else if((n&1) == 0 && (m&1) == 1)
        {
            int xor_ = 0;
            for(int& val : nums1)
                xor_ = xor_^val;
            return xor_;
        }
        else
        {
            int xor_ = 0;
            for(int& val : nums1)
                xor_ = (xor_^val);
            for(int& val : nums2)
                xor_ = (xor_^val);
            return xor_;
        }
        return 0;
    }
};