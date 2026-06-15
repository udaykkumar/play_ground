class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        COL = len(board)
        ROW = len(board[0])
        
        def backtrack(col:int, row:int, w:str) -> bool :
            if not w: return True
            
            if row < 0 or row == ROW or col < 0 or col == COL \
                    or board[col][row] != w[0]:
                return False
            
            board[col][row] = '?'
            for c, r in [ (0,1), (1,0), (0,-1), (-1,0)]: 
                if backtrack( col+c, row+r, w[1:]) :
                    return True
            board[col][row] = w[0]
            
            return False
        
        for col in range(COL):
            for row in range(ROW):
                if backtrack(col, row, word) :
                    return True
        
        return False