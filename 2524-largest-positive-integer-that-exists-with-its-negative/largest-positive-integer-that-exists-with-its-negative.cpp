class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int high = nums.size() - 1;
        int low = 0;
        while(high > low)
        {
            if(nums[high] == -nums[low])
                return nums[high];
            else if(-nums[low] > nums[high])
            {
                ++low;
            }
            else
            {
                --high;
            }
        }
        return -1;
    }
};