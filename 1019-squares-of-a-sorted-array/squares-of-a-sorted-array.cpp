class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> newRes;
        for(int &num : nums)
        {
            newRes.push_back(num*num);
        }
        sort(begin(newRes), end(newRes));
        return newRes;
    }
};