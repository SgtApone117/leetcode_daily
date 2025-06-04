class Solution:
    def dfs(self,box, status, candies, keys, containedBoxes, visited, foundBoxes):
        if box in visited:
            return 0
        if status[box] == 0:
            foundBoxes.add(box)
            return 0
        visited.add(box)
        candiesCollected = candies[box]
        for insideBox in containedBoxes[box]:
            candiesCollected += self.dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes)
        
        for boxKey in keys[box]:
            status[boxKey] = 1
            if boxKey in foundBoxes:
                candiesCollected += self.dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes)
        return candiesCollected

    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        candiesCollected = 0
        visited = set()
        foundBoxes = set()
        print(candies)
        for box in initialBoxes:
            candiesCollected += self.dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes)
        return candiesCollected