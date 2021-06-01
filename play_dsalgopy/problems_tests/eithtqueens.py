'''
Created on May 31, 2021

@author: kumarkud
'''
import unittest
from problems.eightqueens import eightqueens




class Test(unittest.TestCase):


    def setUp(self):
        pass


    def tearDown(self):
        pass


    def testEightQuens(self):
        e = eightqueens()
        print(e.solve())
        e.show()



if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testEightQuens']
    unittest.main()