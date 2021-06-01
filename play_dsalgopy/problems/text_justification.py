'''
Created on Jun 1, 2021

@author: kumarkud
'''
from problems_tests import text_justification

class text_justification():
    '''
    classdocs
    '''


    def __init__(self):
        '''
        Constructor
        '''
    

    """
        [ .... ]
        [ W1 W2 ..  Wn ]
        Size(W1) + Size(W2) + 1 Space
        Size(W1) + Size(W2) + 2 spaces
        maxWidth = 16

        words = ["This", "is", "an", "example", "of", "text", "justification."], 
    """
    def solve(self, words:list[str], maxWidth : int) -> list[str]:
        l , lw = 0
        for w in words:
            lw += len(w)
            if lw + len(l) <= maxWidth:
      