class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> st,ts;
        for(int i = 0; i < s.length(); i++)
        {
            if(st[s[i]] != ts[t[i]]) return false;
            st[s[i]] = i+1;
            ts[t[i]] = i+1;
        }
        return true;
    }
};