class Solution {
public:
    void sortColors(vector<int>& nums) {
        int curr  = 0;
        int start = 0;
        int end = nums.size()-1;

        while(curr <= end)
        {
            if(0 == nums[curr])
            {
                swap(nums[curr], nums[start]);
                curr++;
                start++;
            }
            else if(1 == nums[curr])
            {
                curr++;
            }
            else
            {
                swap(nums[curr], nums[end]);
                end--;
            }
        }
    }
};