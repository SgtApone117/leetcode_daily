class Solution {
public:
    typedef long long int ll;
    string multiply(string a, string b) {
        if("0" == a || "0" == b)
            return "0";
        int n = a.length();
        int m = b.length();
        vector<int> res(n+m, 0);

        for(int i = n-1; i >= 0; --i)
        {
            for(int j = m-1; j >= 0; --j)
            {
                res[i+j+1] += (a[i]-'0') * (b[j]-'0');
                res[i+j]   += res[i+j+1]/10;
                res[i+j+1] = res[i+j+1]%10;
            }
        }
        int i = 0;
        while(i < res.size() && res[i] == 0) ++i;

        string res_str = "";
        while(i < res.size()) res_str.push_back(res[i++]+'0');
        return res_str;
    }
};