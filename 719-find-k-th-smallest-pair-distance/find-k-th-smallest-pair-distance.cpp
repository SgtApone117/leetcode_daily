class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //BRUTE FORCE PRIORITY QUEUE
        int n = nums.size();
        int maxEle = *max_element(begin(nums), end(nums));
        vector<int> vec(maxEle+1, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int diff_bet_pairs = abs(nums[i] - nums[j]);
                vec[diff_bet_pairs]++;
            }
        }
        for(int i = 0; i < maxEle+1; i++)
        {
            k -= vec[i];
            if(k <= 0)
            {
                return i;
            }
        }
        return -1;
    }
};