class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(char& ch : s)
        {
            mp[ch]++;
        }
        for(char& ch : s)
        {
            if(mp[ch] >=3)
            {
                mp[ch] -= 2;
            }
        }
        int len = 0;
        for(auto& val : mp)
        {
            len += val.second;
        }
        return len;
    }
};