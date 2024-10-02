class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        unordered_map<int,int> mp;
        int x = 1;
        for(int& i : temp)
        {
            if(!mp.count(i))
            {
                mp[i] = x;
                x++;
            }
        }

        for(int i = 0; i < arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};