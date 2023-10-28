class Solution {
public:
    int MOD = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> t;
    long long solve(int ch, int n)
    {
        if(n == 0)
        {
            return 1;
        }

        if(t[ch][n] != -1)
        {
            return t[ch][n];
        }
        /*
        a -> e
        e -> a,i
        i -> a,e,o,u
        o -> i,u
        u -> a
        */

        if(ch == a)
        {
            return t[ch][n] = solve(e, n-1) % MOD;
        }
        else if(ch == e)
        {
            return t[ch][n] = (solve(a, n-1) + solve(i, n-1)) % MOD;
        }
        else if(ch == i)
        {
            return t[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % MOD;
        }
        else if(ch == o)
        {
            return t[ch][n] = (solve(i, n-1) + solve(u, n-1)) % MOD;
        }
        else
        {
            return t[ch][n] = (solve(a, n-1)) % MOD;
        }
        return t[ch][n] = 0;
    }

    int countVowelPermutation(int n) 
    {
        t.resize(5, vector<long long>(n+1,-1));
        long result = 0;
        result = (result + solve(a, n-1)) % MOD;
        result = (result + solve(e, n-1)) % MOD;
        result = (result + solve(i, n-1)) % MOD;
        result = (result + solve(o, n-1)) % MOD;
        result = (result + solve(u, n-1)) % MOD;
        return result;
    }
};