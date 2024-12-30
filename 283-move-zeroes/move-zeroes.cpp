class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // point to zero
        int j = 0; // keep moving ahead and swaps when non zero is encountered
        while(j < n)
        {
            if(nums[j] != 0)
            {
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }
    }
};