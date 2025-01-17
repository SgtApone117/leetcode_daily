class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> ps;
        unordered_map<string,char> sp;
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word)
        {
            words.push_back(word);
        }

        if(pattern.length() != words.size()) return false;
        for(int i = 0; i < pattern.length(); i++)
        {
            string str = words[i];
            char x = pattern[i];
            if(sp[str] && sp[str] != x) return false;
            if(ps.count(x) && ps[x] != str) return false;

            sp[str] = x;
            ps[x] = str;
        }
        return true;
        
    }
};