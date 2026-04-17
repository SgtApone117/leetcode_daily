class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = INT_MIN;
        int cnt = 0;
        for(auto num : nums)
        {
            if(num == ele)
            {
                cnt++;
            }
            else if(cnt == 0)
            {
                ele = num;
                cnt = 1;
            }
            else
            {
                cnt--;
            }
        }

        cnt = 0;
        for(auto num : nums)
        {
            if(num == ele)
            {
                cnt++;
            }
        }
        if(cnt > nums.size() / 2)
            return ele;
        return -1;
    }
};