class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp(n);
        for(int &val : arr)
        {
            mp[2*val]++;
        }

        for(int &val : arr)
        {
            if(val == 0 && mp[val] > 1)
            {
                return true;
            }
            if(mp.find(val) != mp.end() && val != 0)
            {
                return true;
            }
        }
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i+1; j < n; j++)
        //     {
        //         if(arr[i] == 2 * arr[j] || 2 *arr[i] == arr[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        return false;
    }
};