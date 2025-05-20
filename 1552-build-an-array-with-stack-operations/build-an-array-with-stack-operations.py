class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        stack = []
        idx = 0
        target_len = len(target)
        for i in range(1, n+1):
            if idx >= target_len:
                break
            if i == target[idx]:
                stack.append("Push")
                idx += 1
            else:
                stack.append("Push")
                stack.append("Pop")
                
            
        return stack
