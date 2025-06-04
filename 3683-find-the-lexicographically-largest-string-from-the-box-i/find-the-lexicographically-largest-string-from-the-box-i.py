class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        n = len(word)
        if numFriends == 1:
            return word
        longest_possible =  n - (numFriends-1)
        result = ""
        for i in range(n):
            if word[i:i+longest_possible] > result:
                result = word[i:i+longest_possible]
        return result