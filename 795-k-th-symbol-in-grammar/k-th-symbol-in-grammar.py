class Solution:
    def power(self,x,n):
        if n == 0:
            return 1
        if n == 1:
            return x 
        if n % 2 == 0:
            return self.power(x*x,n//2)
        return x*self.power(x,n-1)

    def solve(self,n,k):
        if n == 1 and k == 1:
            return 0
        mid = self.power(2,n-1)//2
        if k <= mid:
            return self.solve(n-1,k)
        else:
            return 1-self.solve(n-1,k-mid)
    def kthGrammar(self, n: int, k: int) -> int:
        return self.solve(n,k)