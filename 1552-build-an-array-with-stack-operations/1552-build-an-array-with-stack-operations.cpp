class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;
        vector<string> res;
        int i = 0;
        while(i < target.size() && stream <= n)
        {
            res.emplace_back("Push");
            if(stream == target[i])
            {
                i++;
            }
            else
            {
                res.emplace_back("Pop");
            }
            stream++;
        }
        return res;
    }
};