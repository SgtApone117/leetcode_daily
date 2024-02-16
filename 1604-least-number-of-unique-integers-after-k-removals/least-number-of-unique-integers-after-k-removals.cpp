class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int &x : arr)
            mp[x]++;
        vector<int> freq;
        for(auto &itr : mp)
        {
            freq.push_back(itr.second);
        }
        sort(begin(freq), end(freq));

        int elementRemoved = 0;

        for(int i = 0; i < freq.size(); i++)
        {
            elementRemoved += freq[i];

            if(elementRemoved > k)
            {
                return freq.size() - i;
            }
        }
        return 0;
    }
};