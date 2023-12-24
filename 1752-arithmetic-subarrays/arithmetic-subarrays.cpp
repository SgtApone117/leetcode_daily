class Solution {
public:
    bool check(vector<int> & arr)
    {
        sort(begin(arr), end(arr));

        int n = arr.size();
        int d = arr[1] - arr[0];

        for(int i = 2; i <n; i++)
        {
            if(arr[i] - arr[i-1] != d)
            {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        int n = l.size();

        vector<bool> result;
        for(int i = 0; i < n; i++)
        {
            int start = l[i];
            int end = r[i];

            vector<int> arr(begin(nums) + start, begin(nums) + end + 1);

            bool isAp = check(arr);

            result.push_back(isAp);
        }
        return result;
    }
};