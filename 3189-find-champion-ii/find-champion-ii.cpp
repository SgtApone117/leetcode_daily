class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // just find vertices with no incoming edges
        vector<int> in_coming_freq (n,0);

        for(vector<int> vec : edges)
        {
            in_coming_freq[vec[1]]++;
        }
        vector<int> champions;
        for(int i = 0; i < n; i++)
        {
            if(in_coming_freq[i] == 0)
            {
                champions.push_back(i);
            }
        }
        if(champions.size() > 1)
        {
            return -1;
        }
        return champions[0];
    }
};