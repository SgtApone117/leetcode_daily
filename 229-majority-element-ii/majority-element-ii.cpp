class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(auto num : nums)
        {
            if(num == ele1)
            {
                cnt1++;
            }
            else if(num == ele2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                ele1 = num;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                ele2 = num;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        int majEle = (n/3) + 1;
        for(auto num : nums)
        {
            if(num == ele1)
            {
                cnt1++;
            }
            else if(num == ele2)
            {
                cnt2++;
            }
        }

        vector<int> result;
        if(cnt1 >= majEle)
        {
            result.emplace_back(ele1);
        }

        if(cnt2 >= majEle && ele1 != ele2)
        {
            result.emplace_back(ele2);
        }

        return result;
    }
};