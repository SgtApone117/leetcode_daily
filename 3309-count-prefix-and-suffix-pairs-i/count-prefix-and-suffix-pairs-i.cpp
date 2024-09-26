class Solution {
private:
    int isPrefixAndSuffix(string word1, string word2)
    {
        for(int i = 0; i < word1.length(); i++)
        {
            if(word1[i] != word2[i])
                return 0;
        }

        int i = word1.length()-1;
        int j = word2.length()-1;
        while(i >= 0 && j >= 0 && i < j)
        {
            if(word1[i] != word2[j])
                return 0;
            i--;
            j--;
        }
        return 1;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        if(1 == n)
            return count;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(words[i].length() <= words[j].length())
                    count += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return count;
    }
};