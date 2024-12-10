class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();

        map<pair<char, int>, int> mp;

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            int l = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == ch) {
                    l++;
                    mp[{ch, l}]++;
                } else {
                    break;
                }
            }
        }


        int result = 0;
        for(auto &it : mp) {
            //char ch = it.first.first;
            int length = it.first.second;
            int freq = it.second;

            if(freq >= 3 && length > result) {
                result = length;
            }
        }

        return result == 0 ? -1 : result;
    }
};