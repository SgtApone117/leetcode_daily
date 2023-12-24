class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int count1 = 0, count2 = 0, el1, el2, n = (int)nums.size();
        for(int i = 0; i < n; i++)
        {
            if(count1 == 0 && nums[i] != el2)
            {
                el1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0 && nums[i] != el1)
            {
                el2 = nums[i];
                count2 = 1;
            }
            else if(el1 == nums[i]) count1++;
            else if(el2 == nums[i]) count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        int cnt1 = 0, cnt2 = 0, maj_condition = (int)(n / 3) + 1;
        vector<int> vec;
        for(int i = 0; i < n; i++)
        {
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }   
        if(cnt1 >= maj_condition) vec.emplace_back(el1);
        if(cnt2 >= maj_condition) vec.emplace_back(el2);
        sort(vec.begin(),vec.end());
        return vec;
    }
};