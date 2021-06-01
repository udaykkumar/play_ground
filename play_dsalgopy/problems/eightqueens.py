'''
Created on May 31, 2021

@author: kumarkud
'''
from math import fabs
from pip._internal import self_outdated_check
import time

class eightqueens():
    '''
    classdocs
    '''

    board = [
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0],
        [0,0,0,0,0,0,0,0]
        ]

    def __init__(self):
        '''
        Constructor
        '''

    def __is_okay_on_horizontal_plane(self, x, y):
        for i in range(0,8):
            if self.board[i][y] == 1:
                return False
        return True
    
    
    def __is_okay_on_vertical_plane(self, x, y):
        for i in range(0,8):
            if self.board[x][i] == 1:
                return False
        return True
    
    def __is_okay_on_tl_br_plane(self, x, y):
        i = x
        j = y
        while i >= 0 and j >= 0 :
            if self.board[i][j] == 1:
                return False
            i -= 1
            j -= 1
        
        i = x
        j = y
        while i < 8 and j < 8 :
            if self.board[i][j] == 1:
                return False
            i += 1
            j += 1
        return True
    
    def __is_okay_on_bl_tr_plane(self, x, y):
        i = x
        j = y
        while i < 8 and j >= 0 :
            if self.board[i][j] == 1:
                return False
            i += 1
            j -= 1
        
        i = x
        j = y
        while i >= 0 and j < 8 :
            if self.board[i][j] == 1:
                return False
            i -= 1
            j += 1
        return True
        
        
    def __is_okay_to_place(self, x, y ):
        
        if not self.__is_okay_on_horizontal_plane(x, y):
            return False
        
        if not self.__is_okay_on_vertical_plane(x, y):
            return False
        
        if not self.__is_okay_on_bl_tr_plane(x, y):
            return False
        
        if not self.__is_okay_on_tl_br_plane(x, y):
            return False
        
        return True
       
    
    def show(self, k = 0):
        if k:
            print (" K -> ", k)
        for r in self.board:
            for c in r:
                print(c,end = " ")
            print()      

    def solve(self, k = 0, x = 0, y = 0):
        if k == 8:
            return True
        
        for j in range( y, 8):
            if self.__is_okay_to_place(x, j):                   
                self.board[x][j] = 1
                if self.solve(k+1, x+1, 0):
                    return True
                self.board[x][j] = 0
            
        return False
        