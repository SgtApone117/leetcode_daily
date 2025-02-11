class Solution(object):
    def removeOccurrences(self, s, part):
        """
        :type s: str
        :type part: str
        :rtype: str
        """
        while True:
            if s.find(part) != -1:
                idx = s.find(part)
                # print(idx)
                s = s[:idx] + s[idx+len(part):]
                # print(s[i])
            else:
                break
        return s

        