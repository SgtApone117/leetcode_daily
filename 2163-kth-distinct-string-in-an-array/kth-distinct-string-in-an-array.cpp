class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> dtst;
        unordered_set<string> dupst;
        for(string& str : arr)
        {
            if(dupst.find(str) != dupst.end())
                continue;
            if(dtst.find(str) == dtst.end())
                dtst.insert(str);
            else
            {
                dtst.erase(str);
                dupst.insert(str);
            }
        }

        for(string& str : arr)
        {
            if(dtst.find(str) != dtst.end())
                k--;
            if(k == 0)
                return str;
        }
        return "";    
    }
};