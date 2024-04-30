class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1;
        int cul_xor = 0;

        ll result = 0;
        for(char &ch : word)
        {
            int shift = ch - 'a';

            cul_xor ^= (1 << shift);

            result += mp[cul_xor];

            for(char ch1 = 'a'; ch1 <= 'j'; ch1++)
            {
                shift = ch1 - 'a';

                ll check_xor = (cul_xor ^ (1 << shift));

                result += mp[check_xor];
            }
            mp[cul_xor]++;
        }
        return result;
    }
};