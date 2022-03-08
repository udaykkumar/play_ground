class Solution:
    ROW = 0
    COL = 0

    def __get_hsum(self, mat: list[list[int]], row: int, col: int) -> int:
        s = 0
        for i in range(col, self.COL):
            if not mat[row][i]:
                break
            s += mat[row][i]
        return s

    def __get_vsum(self, mat: list[list[int]], row: int, col: int) -> int:
        s = 0
        for i in range(row, self.ROW):
            if not mat[i][col]:
                break
            s += mat[i][col]
        return s

    def __get_dsum(self, mat: list[list[int]], row: int, col: int) -> int:
        s = 0
        i = row
        j = col
        while i < self.ROW and j < self.COL:
            if not mat[i][j]:
                break
            s += mat[i][j]
            i += 1
            j += 1

        i = row
        j = col
        while i >= 0 and j >= 0:
            if not mat[i][j]:
                break
            s += mat[i][j]
            i -= 1
            j -= 1

        s -= mat[row][col]
        return s

    def __get_anti_dsum(self, mat: list[list[int]], row: int, col: int) -> int:
        s = 0
        i = row
        j = col
        while i >= 0 and j < self.COL:
            if not mat[i][j]:
                break
            s += mat[i][j]
            i -= 1
            j += 1

        i = row
        j = col
        while i < self.ROW and j >= 0:
            if not mat[i][j]:
                break
            s += mat[i][j]
            i += 1
            j -= 1

        s -= mat[row][col]
        return s

    def longestLine(self, mat: list[list[int]]) -> int:
        self.ROW = len(mat)
        self.COL = len(mat[0])
        maxline = 0
        for row in range(self.ROW):
            for col in range(self.COL):
                mx = 0
                mx = max(self.__get_vsum(mat, row, col), mx)
                mx = max(self.__get_hsum(mat, row, col), mx)
                mx = max(self.__get_dsum(mat, row, col), mx)
                mx = max(self.__get_anti_dsum(mat, row, col), mx)
                maxline = max(mx, maxline)
        return maxline
    
    
    
    