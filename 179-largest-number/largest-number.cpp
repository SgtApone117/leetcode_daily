class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        QuickSort(nums, 0, n-1);
        if(nums[0] == 0)
            return "0";
        string numStr;
        for(int &num : nums)
        {
            numStr += to_string(num);
        }
        return numStr;
    }

    void QuickSort(vector<int>& nums, int low, int high)
    {
        int pivot;
        if(low < high)
        {
            pivot = partition(nums, low, high);
            QuickSort(nums, low, pivot-1);
            QuickSort(nums, pivot+1, high);
        }
    }

    int partition(vector<int> &nums, int low, int high)
    {
         int pivot = nums[high];
        int lowIndex = low;
        for (int i = low; i < high; ++i) {
            if (compare(nums[i], pivot)) {
                swap(nums[i], nums[lowIndex]);
                ++lowIndex;
            }
        }
        swap(nums[lowIndex], nums[high]);
        return lowIndex;
    }

    bool compare(int firstNum, int secondNum) {
        return to_string(firstNum) + to_string(secondNum) >
               to_string(secondNum) + to_string(firstNum);
    }
};