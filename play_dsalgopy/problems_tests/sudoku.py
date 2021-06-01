'''
Created on May 31, 2021

@author: kumarkud
'''
import unittest
from problems.sudoku import sudoku


class Test(unittest.TestCase):


    def setUp(self):
        pass


    def tearDown(self):
        pass


    def testSudoku(self):
        sudoku().solve()
        pass


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testSudoku']
    unittest.main()