class Solution:
    def removeVowels(self, s: str) -> str:
        ns = ""
        for c in s :
            ns += c if c not in "aeiou" else ""
        return ns
        