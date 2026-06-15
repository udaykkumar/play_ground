'''
Created on Jun 8, 2021

@author: kumarkud
'''

class permutations_II:
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
    def permuteUnique(self, nums: list[int]) -> list[list[int]]:
        resDict = {}
        lnums = len(nums)
        def backtrack(start):
            if start == lnums:
                k = ','.join([str(ch) for ch in (nums)])
                if k not in resDict:
                    resDict[k] = list(nums)
                return
        
            for i in range(start, lnums):
                nums[i], nums[start] = nums[start], nums[i]
                backtrack(start+1)
                nums[i], nums[start] = nums[start], nums[i]
        
        backtrack(0)        
            
        return resDict.values()


print( permutations_II().permuteUnique(nums = [1,1,2]))