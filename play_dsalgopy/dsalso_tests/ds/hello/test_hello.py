'''
Created on Apr 20, 2021

@author: Uday
'''
import unittest
from dsalgo.ds.hello.hello import Hello


class Test(unittest.TestCase):


    def setUp(self):
        pass


    def tearDown(self):
        pass


    def testHello(self):
        self.assertEqual(str(Hello()), "Hello Here", "We see this message on failure")
        pass


if __name__ == "__main__":
    #import sys;sys.argv = ['', 'Test.testHello']
    unittest.main()