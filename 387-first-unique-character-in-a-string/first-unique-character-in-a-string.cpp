class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        int index = -1;
        for(long long int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for(long long int i = 0; i < s.length(); i++)
        {
            if(mp[s[i]] == 1)
            {
                index = i;
                break;
            } 
        }
        
        return index;
    }
};