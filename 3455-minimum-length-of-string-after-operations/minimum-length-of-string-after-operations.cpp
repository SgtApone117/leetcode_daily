class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        int len = 0;
        for(char& ch : s)
        {
            freq[ch-'a']++;
            if(freq[ch-'a'] >= 3)
            {
                freq[ch-'a'] -= 2;
            }
        }

        for(int& val : freq)
        {
            len += val;
        }
        
        return len;
    }
};