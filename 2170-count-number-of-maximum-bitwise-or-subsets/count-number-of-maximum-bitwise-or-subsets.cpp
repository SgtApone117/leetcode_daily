class Solution {
public:
    int calculateSubSets(int idx, vector<int>& nums, int currOr, int maxOr)
    {
        if(idx == nums.size())
        {
            if(currOr == maxOr)
                return 1;
            else
                return 0;
        }
        //take the count
        int taken_count = calculateSubSets(idx+1, nums, (currOr | nums[idx]), maxOr);

        //dont take the count
        int not_take_count = calculateSubSets(idx+1, nums, currOr, maxOr);
        return taken_count + not_take_count;
    }
    int countMaxOrSubsets(vector<int>& nums) {

        int maxOr = 0;
        for(int &num : nums)
        {
            maxOr = (num | maxOr);
        }
        int count = 0;
        cout << maxOr << endl;
        return calculateSubSets(0, nums, 0, maxOr);
    }
};