'''
Created on Jun 8, 2021

@author: kumarkud
'''

class combination_sum:
    '''
    classdocs
    '''

    
    def __init__(self):
        '''
        Constructor
        '''

    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        
        finList = []

        def recurse(left, combination, start):
            if left == 0:
                finList.append(list(combination))
                return
            
            if left < 0:
                return

            for i in range(start, len(candidates)):
                combination.append(candidates[i])
                recurse(left - candidates[i], combination, i)
                combination.pop()
    
        recurse(target, [], 0)
        return finList
    
print( combination_sum().combinationSum(candidates = [2,3,6,7], target = 7))  