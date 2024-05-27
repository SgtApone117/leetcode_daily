class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        for(int i = 0; i <= n; i++)
        {
            int idx = lower_bound(begin(nums), end(nums), i) - begin(nums);

            int count = n - idx;
            if(count == i)
                return i;
        }
        return -1;
    }
};