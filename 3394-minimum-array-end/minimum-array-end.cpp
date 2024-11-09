class Solution {
public:
    typedef long long ll;
    long long minEnd(int n, int x) {
        ll val = x;
        n--;
        while(n > 0)
        {
            val = ((val+1)|x);
            n--;
        }
        return val;
    }
};