class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        pvt = [pivot]*nums.count(pivot)
        lss = [x for x in nums if x < pivot]
        mrr = [x for x in nums if x > pivot]
        lss.extend(pvt)
        lss.extend(mrr)
        # print(lss)
        return lss
        #print(pvt)
        # print(mrr)
        # return lss+pivot+mrr

        