class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i, count, curr;
        i = 0, curr = 0;
        while(i < n)
        {
            char ch = chars[i];
            count = 0;
            while(i < n && ch == chars[i])
            {
                i++;
                count+=1;
            }
            chars[curr] = ch;
            curr++;
            if(count > 1)
            {
                string s = to_string(count);
                for(char &ch : s)
                {
                    chars[curr] = ch;
                    curr++;
                }
            }
        }
        return curr;
    }
};