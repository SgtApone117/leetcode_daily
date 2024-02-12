class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, vote = 0, candidate = -1;
        for(int &num : nums)
        {
            if(0 == vote)
            {
                candidate = num;
                vote++;
            }
            else
            {
                if(candidate == num)
                {
                    vote++;
                }
                else
                {
                    vote--;
                }
            }
        }
        int count = 0;
        for(int &num : nums)
        {
            if(num == candidate)
            {
                count++;
            }
        }

        if(count > nums.size() / 2)
        {
            return candidate;
        }
        return -1;
    }
};