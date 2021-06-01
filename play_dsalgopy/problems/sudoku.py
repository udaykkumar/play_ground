'''
Created on May 31, 2021

@author: kumarkud
'''

class sudoku():
    '''
    classdocs
    '''

    board = [
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0],
            ]
    
    
    def __init__(self):
        '''
        Constructor
        '''
    
    

    
    def __is_okay_to_place_on_horizonral_place(self, k, x, y):
        for i in range(0,9):
            if self.board[x][i] == k :
                return False
        return True
    
    def __is_okay_to_place_on_vertical_place(self, k,  x, y):
        for i in range(0,9):
            if self.board[i][y] == k:
                return False
        return True
    
    def __is_okay_to_place_in_grid(self, k, x, y):
        for i in range(x, x+3):
            for j in range(y, y+3):
                if i >= 9 or j >= 9 or i < 0 or j < 0 :
                    return False
                if self.board[i][j] == k:
                    return False
        return True    
    
    
    def show(self, k = 0):
        if k:
            print("k ->", k)
        
        for r in self.board:
            for c in r:
                print(c, end = " ")
            print()
    
    def solve(self, k = 1, x = 0, y = 0 ):
        
        if k == 9:
            return True
        
        self.show(k)
        
        for gx in range(x, 3):
            for gy in range(y, 3):
                if not self.__is_okay_to_place_in_grid(k, gx, gy) :
                    continue
                self.board[gx][gy] = k
                if self.solve(k, x, y):
                    return True
                self.board[gx][gy] = 0
        
        if self.solve(k+1, x, y):
            return True
        return False