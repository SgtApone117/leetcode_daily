class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        div_m = 0
        non_div_m = 0
        for i in range(1,n+1):
            if i % m == 0:
                div_m += i
            else:
                non_div_m += i
        return (non_div_m-div_m)