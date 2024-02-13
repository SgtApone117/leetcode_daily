class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = -1;
        for(int &x : nums)
        {
            if(0 == count)
            {
                count++;
                candidate = x;
            }
            else
            {
                if(x == candidate)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return candidate;
    }
};