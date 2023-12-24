class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largestNum    = INT_MIN;
        int secondLargest = INT_MIN;

        int smallestNum    = INT_MAX;
        int secondSmallest = INT_MAX;

        for(auto& num : nums)
        {
            if(num > largestNum)
            {
                secondLargest = largestNum;
                largestNum    = num;
            }
            else
            {
                secondLargest = max(num, secondLargest);
            }

            if(num < smallestNum)
            {
                secondSmallest = smallestNum;
                smallestNum    = num; 
            }
            else
            {
                secondSmallest = min(num, secondSmallest);
            }
        }
        return ((largestNum * secondLargest) - (smallestNum * secondSmallest));
    }
};