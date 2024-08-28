class Solution {
public:
    int t[38];
    int solve(int n)
    {
        if(0 == n)
            return 0;
        if(1 == n)
            return 1;
        if(2 == n)
            return 1;
        if(-1 != t[n])
            return t[n];
        return t[n] = solve(n-3)+solve(n-2)+solve(n-1); 
    }
    int tribonacci(int n) 
    {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};