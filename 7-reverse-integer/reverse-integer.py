class Solution:
    def solve(self, num: int, res: list) -> None:
        if num < 10:
            res.append(num)
            return
        res.append(num%10)
        self.solve(num//10,res)
        return
    def reverse(self, x: int) -> int:
        res = []
        self.solve(abs(x),res)
        print(res)
        number = 0
        unit_place = 10**(len(res)-1)
        for digit in res:
            number += digit*unit_place
            unit_place //= 10
        if number < -1 * (2**31 - 1) or number > 2**31:
            return 0
        return -1*number if x < 0 else number