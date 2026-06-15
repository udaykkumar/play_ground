class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        START = 0
        END   = 1
        slots = []
        
        for interval in intervals:
            if interval[ END ]  < newInterval[ START ] :
                slots.append(interval)
            elif interval[ START ] > newInterval [ END ] :
                slots.append( newInterval )
                newInterval = interval
            else:
                newInterval[ START ] = min( interval[ START ], newInterval[ START ]) 
                newInterval[ END   ] = max( interval[ END   ], newInterval[ END   ]) 
        
        slots.append(newInterval)        
        return slots   