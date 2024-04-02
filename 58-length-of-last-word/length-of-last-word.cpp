class Solution {
public:
    static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

    int lengthOfLastWord(string s, string del = " ") {
        vector<int> vec;
        rtrim(s);
        int start, end = -1*del.size();
        do {
            start = end + del.size();
            end = s.find(del, start);
            vec.emplace_back(s.substr(start, end - start).size());
            } while (end != -1);
            return vec.back();
    }
};