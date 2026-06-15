class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start, end = 0, len(nums) - 1
        
        while start <= end:
            
            mid = start + (end - start) // 2
            
            if nums[mid] == target: return mid
            
            # sorted one here first
            if nums[mid] >= nums[start]:
                # If target within list , move end down
                if target >= nums[start] and target < nums[mid]:
                    end = mid - 1
                else:
                    # move start up 
                    start = mid + 1
            else:
                # Unsorted List
                if target <= nums[end] and target > nums[mid]:
                    start = mid + 1
                else:
                    end = mid - 1
        return -1
                    
                
            
            
        