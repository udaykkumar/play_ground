"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    memo = {}
    
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        s = 0
        for e in employees:
            if e.id == id:
                s = e.importance 
                for so in e.subordinates:
                    s += self.getImportance(employees, so)
        return s           
                