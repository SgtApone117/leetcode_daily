class Solution {
public:
    string compressedString(string word) {
        string s = "";
        int count = 0;
        char curr_char = word[0];
        for(char ch : word)
        {
            if(ch != curr_char || count == 9)
            {
                s.push_back(count+'0');
                s.push_back(curr_char);
                count = 0;
                curr_char = ch;
            }
            count++;
        }
        if(count > 0)
        {
            s.push_back(count+'0');
            s.push_back(curr_char);
        }
        return s;
    }
};