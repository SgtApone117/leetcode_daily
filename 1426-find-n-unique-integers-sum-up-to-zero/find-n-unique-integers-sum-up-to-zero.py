class Solution:
    def sumZero(self, n: int) -> List[int]:
        arr = []
        if (n&1) != 0:
            arr.append(0)
        for i in range(1,(n//2) + 1):
            arr.append(i)
            arr.append(-i)
            i += 1
        return arr