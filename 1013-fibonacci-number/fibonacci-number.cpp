class Solution {
public:
    int solve(int n, int t[])
    {
        if(-1 != t[n])
            return t[n];
        if(0 == n)
            return 0;
        if(1 == n)
            return 1;
        return t[n] = fib(n-1)+fib(n-2);
    }
    int fib(int n) 
    {
        int t[31];
        memset(t, -1, sizeof(t));
        return solve(n, t);
    }
};