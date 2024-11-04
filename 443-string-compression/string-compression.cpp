class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i, j, last, count;
        i = 0, j = 0, last = 0, count = 0;
        char ch = chars[0];
        if(1 == n)
            return 1;
        while(i < n)
        {
            if(ch == chars[i])
            {
                i++;
                count+=1;
            }
            else if(ch != chars[i])
            {
                chars[j] = ch;
                j++;
                if(count > 1)
                {
                    string s = to_string(count);
                    for(int x = 0; x < s.length(); x++)
                    {
                        chars[j] = s[x];
                        j++;
                    }
                }
                
                ch = chars[i];
                count = 0;
                //cout << ch << endl;
            }
        }
        if(count > 1)
        {
            chars[j] = ch;
            j++;
            if(count > 1)
            {
                string s = to_string(count);
                for(int x = 0; x < s.length(); x++)
                {
                    chars[j] = s[x];
                    j++;
                }
            }
            
            ch = chars[i];
            count = 0;
        }else
        {
            cout << j << endl;
            chars[j] = ch;
            j++;
        }
        return j;
    }
};