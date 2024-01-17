class Solution {
public:
    //Using Map and HashSet
    bool usingMapAndSet(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        for(int &x : arr)
        {
            mp[x]++;
        }
        unordered_set<int> st;
        for(auto &it : mp)
        {
            int freq = it.second;
            if(st.find(freq) != st.end())
            {
                return false;
            }
            st.insert(freq);
        }
        return true;
    }
    bool uniqueOccurrences(vector<int>& arr) {
        return usingMapAndSet(arr);
    }
};