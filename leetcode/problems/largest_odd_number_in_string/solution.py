class Solution:
    def largestOddNumber(self, num: str) -> str:
        i = 0
        ln = 0
        while i < len(num):
            n = ord( num[i] )
            i+=1
            if n%2 == 0 :
                continue
            ln = max(i,ln)
            
        return num[:ln]