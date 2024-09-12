class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        vector<int> freq(26, 0);
        for(char &ch : allowed)
            freq[ch-'a'] = 1;
        int count = 0;
        for(string &word : words)
        {
            bool flag = true;
            for(char &ch : word)
            {
                if(freq[ch-'a'] != 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                count++;
        }
        return count;
    }
};