class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int second_largest = 0;

        for(auto& num : nums)
        {
            if(num > largest)
            {
                second_largest = largest;
                largest = num;
            }
            else
            {
                second_largest = max(second_largest, num);
            }
        }
        return (largest-1) * (second_largest-1);
    }
};