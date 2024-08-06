class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        int result = 0;
        for(char& chc : word)
        {
            ++freq[chc - 'a'];
        }
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i = 0; i < 26; i++)
        {
            int fq = freq[i];

            int press = (i / 8) + 1;

            result += press * fq;
        }
        return result;
    }
};