class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        rdict = {}
        lnums = len(nums)
        def backtrack(nums, start, comb):
            k = ",".join([str(x) for x in sorted(comb)] )
            if k not in rdict:
                rdict[k] = list(comb)
            
            for i in range( start, lnums ):
                comb.append( nums[i] )
                backtrack(nums, i+1, comb)
                comb.pop()
        
        backtrack(nums, 0, [])
        return rdict.values()