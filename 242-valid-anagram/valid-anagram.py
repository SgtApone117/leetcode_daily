class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        dt = {}
        for char in s:
            if dt.get(char):
                dt[char] += 1
            else:
                dt[char] = 1
        for char in t:
            if char not in dt:
                return False
            dt[char] -= 1
            if dt.get(char) == 0:
                dt.pop(char)
        return True