class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) 
    {
        vector<int> num_arr;
        int n = (int)words.size();
        vector<int> result;
        int j = -1;
        for(int i = 0; i < n; i++)
        {
            if(words[i] == "prev")
            {
                if(j < 0)
                    result.emplace_back(-1);
                else
                    result.emplace_back(num_arr[j]);
                j--;
            }
            else
            {
                num_arr.emplace_back(stoi(words[i]));
                j = num_arr.size() - 1;
            }    
        }
        return result;
    }
};