class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(i+1 < n && nums[i] % 2 == nums[i+1] % 2)
                return false;
        }
        return true;
    }
};