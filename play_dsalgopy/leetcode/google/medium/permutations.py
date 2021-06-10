'''
Created on Jun 8, 2021

@author: kumarkud
'''

class permutations:
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
    def permute(self, nums: list[int]) -> list[list[int]]:
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

print( permutations().permute(nums = [1,2,3]))