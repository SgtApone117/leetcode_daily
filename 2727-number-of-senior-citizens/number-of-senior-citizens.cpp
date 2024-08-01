class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto &str : details)
        {
            if(stoi(str.substr(11, 2)) > 60)
                count++;
        }
        return count;
    }
};