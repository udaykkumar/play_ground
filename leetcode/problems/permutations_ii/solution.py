class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        resDict = {}
        lnums = len(nums)
        def backtrack(start):
            #print(nums, start)
            if start == lnums:
                k = ','.join([str(ch) for ch in (nums)])
                #print(k)
                if k not in resDict:
                    resDict[k] = list(nums)
                return
        
            for i in range(start, lnums):
                nums[i], nums[start] = nums[start], nums[i]
                backtrack(start+1)
                nums[i], nums[start] = nums[start], nums[i]
        
        backtrack(0)        
            
        return resDict.values()