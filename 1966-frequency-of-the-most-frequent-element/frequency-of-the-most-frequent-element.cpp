class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(begin(nums), end(nums));
       int n = nums.size();
       int result = 0;
       int l = 0;
       long currSum = 0;
       for(int r = 0; r < n; r++) 
       {
            long target = nums[r];
            currSum += nums[r];
            while((r-l+1)*target - currSum > k) 
            { //window shrink
                currSum -= nums[l];
                l++;
             }
            result = max(result, r-l+1);
        }
    return result; 
    }
};