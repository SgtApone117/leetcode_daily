class Solution {
public:
    int fib(int n) {
        if(0 == n)
            return 0;
        if(1 == n)
            return 1;
        return fib(n-1)+fib(n-2);
    }
};