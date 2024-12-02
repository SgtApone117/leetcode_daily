class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int count = 0;
        while(ss >> word)
        {
            size_t found = word.find(searchWord);
            if(found != string::npos)
            {
                if(found == 0)
                {
                    count++;
                    return count;
                }
            }
            count++;
        }
        return -1;
    }
};