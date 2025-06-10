class Solution:
    def maxDifference(self, s: str) -> int:
        mp = [0] * 26
        for ch in s:
            mp[ord(ch)-ord('a')] += 1
        max_res = float("-inf")
        for odd in mp:
            if odd == 0:
                continue
            if odd % 2 != 0:
                print(odd)
                for even in mp:
                    if even == 0:
                        continue
                    if even % 2 == 0:
                        print(even)
                        max_res = max(max_res, odd-even)
        return max_res