'''
Created on Jun 1, 2021

@author: kumarkud
'''
import unittest
from problems.text_justification import text_justification



class Test(unittest.TestCase):


    def setUp(self):
        pass


    def tearDown(self):
        pass


    def testtext_justification(self):
        t = text_justification()
        t.solve(["This", "is", "an", "example", "of", "text", "justification."], 16)

if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testtext_justification']
    unittest.main()