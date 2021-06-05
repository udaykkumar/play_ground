'''
Created on Jun 2, 2021

@author: kumarkud
'''
from typing import list


class insert_intervals():
    '''
    classdocs https://leetcode.com/problems/insert-interval/
    '''


    def __init__(self):
        '''
        Constructor
        '''
    
    


    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        
        START = 0
        END   = 1
        slots = []
        
        for interval in intervals:
            if interval[ END ]  <= newInterval[ START ] :
                slots.append(interval)
            elif interval[ START ] > newInterval [ END ] :
                slots.append( newInterval )
                newInterval = interval
            else:
                newInterval[ START ] = min( interval[ START ], newInterval[ START ]) 
                newInterval[ END   ] = max( interval[ END   ], newInterval[ END   ]) 
        
        slots.append(newInterval)        
        return slots   
        
        
insert_intervals().insert(intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8])
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        