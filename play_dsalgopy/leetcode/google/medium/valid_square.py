'''
Created on Jun 5, 2021

@author: kumarkud
'''


class valid_square():
    '''
    classdocs
    '''

    
    def __init__(self):
        '''
        Constructor
        '''
    
    def __distance(self, p1:list[int], p2:list[int]):
        x1 = p1[0]
        x2 = p2[0]
        y1 = p1[1]
        y2 = p2[1]
        return ((x1-x2)**2) + ((y1-y2)**2)
  
        
    def validSquare(self, p1: list[int], p2: list[int], p3: list[int], p4: list[int]) -> bool:
        distances = [self.__distance(p1, p2), 
                     self.__distance(p2, p3),
                     self.__distance(p3, p4),
                     self.__distance(p4, p1),
                     self.__distance(p1, p3),
                     self.__distance(p2, p4)]
        
        distances.sort()
        
        side = distances[0]
        # Zero side is invalid
        if not side:
            return False 
        
        # All Sides must me Equal
        for i in range(0,4):
            if distances[i] != side:
                return False
        
        # Equal Diagnols
        diag = distances[4]
        for i in range(4,6):
            if distances[i] != diag:
                return False        
        
        return True
    

print(valid_square().validSquare([1,1],  [5,3], [3,5], [7,7]) )
print(valid_square().validSquare([0,0],  [1,1], [1,0], [0,1]) )
print(valid_square().validSquare([1,0], [-1,0], [0,1], [0,-1]))