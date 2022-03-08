class Solution:
    def hammingWeight(self, n: int) -> int:
        totals = 0
        while n :
            if (n%2) == 1 :
                totals += 1
            n = int(n/2)
        return totals