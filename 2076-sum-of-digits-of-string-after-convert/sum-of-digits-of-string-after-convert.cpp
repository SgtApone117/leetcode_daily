class Solution {
public:
    typedef long long ll;
    int getLucky(string s, int k) {
        int n = s.length();
        string numString = "";
        ll num = 0;
        for(char &ch : s)
        {
            numString += to_string(ch%96);
        }
        int sum;
        int temp;
        while(k--)
        {
            sum = 0;
            for(char &ch : numString)
            {
                sum += ch-'0';
            }
            temp = sum;
            numString = to_string(temp);
        }
        return temp;
    }         
};