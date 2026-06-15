class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = list([])
        lnums   = len(nums)
        def backtrack( start, comb ):
            results.append(list(comb))
                
            if start == lnums:
                return
            
            for i in range(start, lnums):
                comb.append( nums[i] )
                backtrack(i+1, comb)
                comb.pop()
        
        backtrack(0, [])    
        return results
            