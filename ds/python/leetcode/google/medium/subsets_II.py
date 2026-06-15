'''
Created on Jun 8, 2021

@author: kumarkud
'''

class subsets_II:
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
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
    

print(subsets_II().subsetsWithDup(nums = [1,2,2]))  
print(subsets_II().subsetsWithDup(nums = [4,4,4,1,4]))   
