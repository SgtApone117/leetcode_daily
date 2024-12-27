class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j < n)     
        {
            if(nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    }
};

// 2 1 i = 0 and j = 1
/*
    i and j both are non zero so update

    nums[i]
*/

// 0 1 0 3 12 i and j 0th and 1st position 
// 1 0 0 3 12 i = 1 j = 2
// 1 0 0 3 12 i = 1 j = 3
// 1 3 0 0 12 i = 2 j = 4
// 1 3 12 0 0 i = 3 j = 5