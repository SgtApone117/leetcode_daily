class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n)
        {
            if((j+1) < n && nums[j] != nums[j+1])
            {
                nums[i] = nums[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        nums[i] = nums[--j];
        i++;
        j++;
        return i;
    }
};
/*
    1 1 2 i = 0, j = 0
    1 1 2 i = 0, j = 1
    1 1 2 i = 1  j = 3  
    nums.size()-swap

    0 0 1 1 1 2 2 3 3 4 i = 0 j = 0
    i = 0 j = 1
    nums[i] = nums[j] i = 1 j = 2
    i = 1 j = 3
    0 1 

*/