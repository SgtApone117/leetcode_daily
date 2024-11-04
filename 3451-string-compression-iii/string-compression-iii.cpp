class Solution {
public:
    string compressedString(string word) {
        int i, index;
        i = 0, index = 0;
        string s = "";
        for(char &ch : word)
        {
            char curr_char = ch;
            int count = 0;
            while(i < word.length() && ch == word[i])
            {
                count++;
                if(count == 9)
                {
                    s.push_back('9');
                    s.push_back(curr_char);
                    count = 0;
                }
                i++;
            }
            if(count > 0)
            {
                s.push_back(count+'0');
                s.push_back(curr_char);
            }
        }
        return s;
    }
};