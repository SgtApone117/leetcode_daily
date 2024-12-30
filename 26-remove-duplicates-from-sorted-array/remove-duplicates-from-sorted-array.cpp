class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int count = 0;
        while(j < n)
        {
            if(nums[i] != nums[j])
            {
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return (i+1);
    }
};