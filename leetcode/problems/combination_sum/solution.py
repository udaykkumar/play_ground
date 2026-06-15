class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
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