class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() == k) return true;
        if(k > s.length())  return false;
        vector<int> freq(26, 0);
        int count_odd = 0;
        for(char& ch : s)
        {
            freq[ch-'a']++;
        }

        for(int i = 0; i < 26; i++)
        {
            if((freq[i]&1) == 1) count_odd++;
        }

        if(count_odd <= k) return true;
        return false;
    }
};