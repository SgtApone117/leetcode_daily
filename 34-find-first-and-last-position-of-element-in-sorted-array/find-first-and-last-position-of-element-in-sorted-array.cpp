class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1, res1 = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
 
        if (nums[mid] > x)
            high = mid - 1;
        else if (nums[mid] < x)
            low = mid + 1;
        else {
            res1 = mid;
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    int res2 = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
 
        if (nums[mid] > x)
            high = mid - 1;
        else if (nums[mid] < x)
            low = mid + 1;
        else {
            res2 = mid;
            low = mid + 1;
        }
    }

    vector<int> nums1;
    nums1.emplace_back(res1);
    nums1.emplace_back(res2);
return nums1;
    }
};