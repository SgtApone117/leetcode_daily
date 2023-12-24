class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> ump;
        int target = arr.size() / 4;
        for(int num : arr)
        {
            ump[num]++;
            if(ump[num] > target)
            {
                return num;
            }
        }
        return -1;
    }
};