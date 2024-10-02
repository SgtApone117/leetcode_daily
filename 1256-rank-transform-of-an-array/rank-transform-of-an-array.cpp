class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        sort(temp.begin(), temp.end());

        unordered_map<int,int> mp;
        vector<int> res;
        int x = 1;
        for(int& i : temp)
        {
            if(mp.find(i) == mp.end())
            {
                mp[i] = x;
                x++;
            }
        }

        for(int& i : arr)
        {
            if(mp.find(i) != mp.end())
                res.push_back(mp[i]);
        }
        return res;
    }
};