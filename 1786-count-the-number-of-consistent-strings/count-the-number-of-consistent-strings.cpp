class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        unordered_set<char> st;
        for(char &ch : allowed)
            st.insert(ch);
        int count = 0;
        for(string &word : words)
        {
            bool flag = true;
            for(int i = 0; i < word.length(); i++)
            {
                if(st.find(word[i]) == st.end())
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