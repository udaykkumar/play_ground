"""
Created on Apr 20, 2021

@author: Uday
"""
import unittest
from dsalgo.ds.single_linked_list import single_linked_list


class Test(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testLinkedListsSimple(self):
        sll = single_linked_list()
        sll.add(0)
        print("print ", sll)
        sll.add(1)
        print("print ", sll)
        pass


if __name__ == "__main__":
    # import sys;sys.argv = ['', 'Test.testLinkedListsSimple']
    unittest.main()
