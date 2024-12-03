class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        vector<int> store;
        for(int& space : spaces)
        {
            store.push_back(s[space]);
            s[space] = '$';
        }
        int n = s.length();
        int j = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != '$')
            {
                result.push_back(s[i]);
            }
            else
            {
                result.push_back(' ');
                result.push_back(store[j]);
                j++;
            }
        }
        return result;
    }
};