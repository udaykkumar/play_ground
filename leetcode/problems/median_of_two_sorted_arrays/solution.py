class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1 = len(nums1)
        l2 = len(nums2)
        lst = [0] * (l1 + l2)
        i = 0
        j = 0
        k = 0
        while i < l1 and j < l2:
            if nums1[i] < nums2[j]:
                lst[k] = nums1[i]
                i += 1
            else:
                lst[k] = nums2[j]
                j += 1
            k += 1
        
        while i < l1 :
            lst[k] = nums1[i]
            i += 1
            k += 1
            
        while j < l2:
            lst[k] = nums2[j]
            j += 1
            k += 1
        
        
        lstLen = len(lst)
        if lstLen%2 == 0:
            mid = int (lstLen/2) - 1
            return (lst[mid] + lst[mid+1])/2
        else:
            mid = int (lstLen/2)
            return lst[mid]
        