class Solution:
    def solve(self, num: int, res: list) -> None:
        if num == 0:
            return res[0]
        res[0] = res[0]*10 + num%10
        return self.solve(num//10,res)

    def reverse(self, x: int) -> int:
        res = [0]
        self.solve(abs(x),res)
        INT_MAX = (2**31)-1
        INT_MIN = -1 * (2**31)
        if res[0] >= INT_MAX or res[0] < INT_MIN:
            return 0
        return -1 * res[0] if x < 0 else res[0]