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

    //using vector and input limits
    bool usingVector(vector<int>& arr)
    {
        vector<int> vec(2001, 0);
        for(int &x : arr)
        {
            vec[x + 1000]++;
        }
        sort(begin(vec), end(vec));
        for(int i = 1; i < 2001; i++)
        {
            if(vec[i] != 0 && vec[i-1] == vec[i])
            {
                return false;
            }
        }
        return true;
    }

    bool uniqueOccurrences(vector<int>& arr) {
        //return usingMapAndSet(arr);
        return usingVector(arr);
    }
};