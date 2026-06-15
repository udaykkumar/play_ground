class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        lnums = len(nums)
        
        def backtrack(start):
            if start == lnums:
                result.append(list(nums))
            
            for i in range(start, lnums):
                nums[i], nums[start] = nums[start], nums[i]
                backtrack(start+1)
                nums[i], nums[start] = nums[start], nums[i]
                
                
            
        backtrack(0)    
        return result