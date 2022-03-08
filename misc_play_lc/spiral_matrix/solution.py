class Solution:
    
    def valid_element(self, matrix, x, y, m, n ):
        if x < 0 or y < 0 :
            return False

        if x >= m or y >= n :
            return False

        if matrix[x][y] == -9823451:
            return False

        return True

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        retList = []
        row = 0
        col = 0
        m = len(matrix)
        n = len(matrix[0])
        
        while True :
            visited_all = False
            # Move right till end
            while self.valid_element(matrix, row, col ,m ,n ):
                retList.append( matrix[row][col] )
                matrix[row][col] = -9823451
                visited_all = True
                col += 1
            col -= 1    
            row += 1    


            # Move Down til end
            while self.valid_element(matrix, row, col, m, n ):
                retList.append( matrix[row][col] )
                matrix[row][col] = -9823451
                visited_all = True
                row += 1
            row -= 1
            col -= 1
        
            # Move left till end
            while self.valid_element(matrix, row, col, m, n ):
                retList.append( matrix[row][col] )
                matrix[row][col] = -9823451
                visited_all = True
                col -= 1
            col += 1
            row -= 1
            
            # Move up
            while self.valid_element(matrix, row, col, m, n ):
                retList.append( matrix[row][col] )
                matrix[row][col] = -9823451
                visited_all = True
                row -= 1
            row += 1
            col += 1
            
            # we can't find means we are done    
            if not visited_all:
                return retList

        return retList
