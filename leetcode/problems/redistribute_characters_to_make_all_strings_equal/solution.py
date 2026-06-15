class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        n_words = len(words)
        if n_words == 1:
            return True
        wmap = {}
        for w in words:
            for c in w:
                if c not in wmap:
                    wmap[c] = 1
                else:
                    wmap[c] += 1
        
    
        for k,v in wmap.items():
            print(k, v, n_words)
            if v%n_words == 0:
                continue
            return False
        
        return True