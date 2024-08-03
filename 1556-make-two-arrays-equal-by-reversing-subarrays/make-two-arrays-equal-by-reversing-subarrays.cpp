class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> ump;
        for(auto &item : target)
            ump[item]++;

        for(auto &item : arr)
        {
            if(ump.find(item) == ump.end())
                return false;
            else
            {
                ump[item]--;
                if(ump[item] == 0)
                    ump.erase(item);
            }
        }
        return true;
    }
};