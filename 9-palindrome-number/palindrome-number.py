class Solution:
    def solve(self, x, digit):
        if x == 0:
            return digit[0]
        digit[0] = digit[0]*10 + x%10
        return self.solve(x//10,digit)
        
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        res = [0]
        self.solve(x,res)
        return res[0] == x
        
        