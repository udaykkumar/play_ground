class Solution:
    def is_valid(self, matrix, row, col, m, n ):
        if row < 0 or col < 0 :
            return False

        if row >= m or col >= n :
            return False

        if matrix[row][col] != 0 :
            return False

        return True
    
    
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [ [ 0 for i in range(n) ] for j in range(n) ]
        row = 0
        col = 0
        m   = n
        i = 1
        while True:
            visited_all = False
        
            # move right
            while self.is_valid(matrix, row, col, m, n ) :
                matrix[row][col] = i
                visited_all = True
                i += 1
                col += 1
            col -= 1
            row += 1

            # move down
            while self.is_valid(matrix, row, col, m, n):
                matrix[row][col] = i
                visited_all = True
                i += 1
                row += 1
            row -= 1
            col -= 1

            # move left
            while self.is_valid(matrix, row, col, m, n):
                matrix[row][col] = i
                visited_all = True
                i += 1
                col -= 1
            col += 1
            row -= 1

            # move up 
            while self.is_valid(matrix, row, col, m, n):
                matrix[row][col] = i
                visited_all = True
                i += 1
                row -= 1
            row += 1
            col += 1
            if not visited_all:
                return matrix

        return matrix