class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        unordered_map<string,int> s1Words;
        s1 = s1 + " " + s2;
        size_t start = 0;
        size_t end;

        while ((end = s1.find(' ', start)) != string::npos) 
        {
           s1Words[s1.substr(start, end - start)]++;
           start = end + 1;
        }

        s1Words[s1.substr(start)]++;
        for(auto &word : s1Words)
        {
            if(word.second == 1)
                result.push_back(word.first);
        }

        
        return result;
    }
};