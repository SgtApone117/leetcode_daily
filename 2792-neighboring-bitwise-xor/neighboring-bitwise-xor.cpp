class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int c_o = 0;
        for(int& val : derived)
        {
            c_o += __builtin_popcount(val);
        }
        if(c_o&1 == 1) return false;
        return true;
    }
};