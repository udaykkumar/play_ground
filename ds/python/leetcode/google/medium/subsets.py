'''
Created on Jun 8, 2021

@author: kumarkud
'''

class subsets:
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
    
    def subsets(self, nums: list[int]) -> list[list[int]]:
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
    

print( subsets().subsets(nums = [1,2,3]) )