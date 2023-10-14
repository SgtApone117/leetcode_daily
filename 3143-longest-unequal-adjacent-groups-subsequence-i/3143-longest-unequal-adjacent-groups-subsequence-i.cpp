class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) 
    {
        int back_ele = groups[0];
        vector<string> result;
        result.emplace_back(words[0]);
        
        for(int i = 1; i < (int)groups.size(); i++)
        {
            if(groups[i] != back_ele)
            {
                back_ele = groups[i];
                result.emplace_back(words[i]);
            }
        }
        return result;
    }
};