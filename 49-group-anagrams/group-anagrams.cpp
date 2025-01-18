class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mp;
        vector<vector<string>> result;
        int idx = 0;
        for(string& str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            if(mp.find(temp) != mp.end())
            {
                result[mp[temp]].push_back(str);
            }
            else
            {
                mp[temp] = idx;
                result.push_back({str});
                idx++;
            }
        }
        return result;
    }
};