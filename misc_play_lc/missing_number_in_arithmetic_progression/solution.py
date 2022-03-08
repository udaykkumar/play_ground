class Solution:
    def missingNumber(self, a: List[int]) -> int:
        n = len(a)
        df = int((a[n-1] - a[0]) / n)
        e  = a[0]
        
        for num in a:
            if num != e :
                return e
            e += df
        
        return e
        
        