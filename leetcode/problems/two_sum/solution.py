class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memo = {}
        for i in range(len(nums)):
            memo[nums[i]] = i
        
        for i in range(len(nums)):
            t = target - nums[i]
            if t in memo:
                if memo[t] == i :
                    continue
                return [i, memo[t]]
    
        return []