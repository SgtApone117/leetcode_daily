class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int maxValue = *max_element(begin(arr), end(arr));
        vector<int> result;
        for(int i = 1; i <= maxValue+k; i++)
        {
            bool flag = false;
            for(int& num : arr)
            {
                if(num == i)
                {
                    flag = true;
                    break;
                }
            }
            if(!flag) result.push_back(i);
        }
        return result[k-1];
    }
};