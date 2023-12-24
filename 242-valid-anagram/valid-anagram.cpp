class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() < t.size()) return false;
        map<char,int> mp, mp1;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            mp1[t[i]]++;
        }
        if(mp.size() != mp1.size()) return false;
        for(auto i = mp.begin(), j = mp1.begin(); i != mp.end(); ++i, ++j)
        {
            if(i->first != j->first) return false;
            if(i->second != j->second) return false;
        }
        return true;
    }
};