class Solution:
    def intersection(self, a: List[int], b: List[int]) -> List[int]:
        a.sort()
        b.sort()
        m = len(a)
        n = len(b)
        res = []
        i = j = 0
        while i < m and j < n:
            if i > 0 and a[i] == a[i-1]:
                i += 1
                continue
            elif a[i] < b[j]:
                i += 1
            elif a[i] > b[j]:
                j += 1
            else:
                res.append(a[i])
                i += 1
                j += 1
        return res