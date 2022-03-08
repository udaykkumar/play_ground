class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        
        # Lets start by Creating a Dictionary for these numbers
        sdict = { "0":0 , "1": 0, "2": 0, "3": 0, "4": 0, "5": 0,
                 "6": 0, "7": 0, "8": 0, "9": 0}
        
        # Process the secret and put into dictionary for O(1) access
        # and while we do that lets just make sure to calculate bulls
        bulls = 0
        slen = len(secret)
        for i in range(slen):
            if secret[i] == guess[i]:
                bulls += 1
                continue
            sdict[ secret[i] ] += 1
        
        # Now lets go through the guess, skip bulls and see if there exists a cow
        cows = 0
        for i in range(slen):
            # Skip Bulls
            if secret[i] == guess[i]:
                continue
            
            # Cows
            if sdict[ guess[i] ] != 0:
                cows += 1
                sdict[ guess[i] ] -= 1

        print(bulls, cows)
        
        return "{}A{}B".format(bulls, cows)