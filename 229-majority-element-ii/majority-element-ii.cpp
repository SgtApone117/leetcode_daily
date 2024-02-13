class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> result;
        int candidate1 = INT_MIN, candidate2 = INT_MIN, vote1 = 0, vote2 = 0;
        for(int &num : nums)
        {
            if(0 == vote1 && num != candidate2)
            {
                vote1++;
                candidate1 = num;
            }
            else if(0 == vote2 && num != candidate1)
            {
                vote2++;
                candidate2 = num;
            }
            else if(num == candidate1)
            {
                vote1++;
            }
            else if(num == candidate2)
            {
                vote2++;
            }
            else
            {
                vote1--;
                vote2--;
            }
        }
        int mini = int(nums.size() / 3) + 1;
        vote1 = 0, vote2 = 0;
        for(int &x : nums)
        {
            if(x == candidate1)
                vote1++;
            else if(x == candidate2)
                vote2++;
        }
        if(vote1 >= mini)
        {
            result.push_back(candidate1);
        }
        if(vote2 >= mini)
        {
            result.push_back(candidate2);
        }
        return result;
    }
};