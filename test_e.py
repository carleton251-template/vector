#!/usr/bin/python3

import unittest
import test_utilities
from gradescope_utils.autograder_utils.decorators import weight

class Tests(unittest.TestCase):
  @weight(1)
  def testVectorPart1(self):
    return_value = test_utilities.runIt('1 E')
    if return_value != None:
        self.fail(return_value)

  @weight(1)
  def testVectorPart2(self):
    return_value = test_utilities.runIt('2 E')
    if return_value != None:
        self.fail(return_value)

