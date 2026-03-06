class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroSeen = false;
        for(char ch : s)
        {
            if(ch == '0')
            {
               zeroSeen = true;
            }
            else if(zeroSeen)
            {
                return false;
            }
        }
       return true;
    }
};