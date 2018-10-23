"""
1.3 Design an algorithm and write code to
remove the duplicate characters in a string
without using any additional buffer. NOTE: One
or two additional variables are fine. An
extra copy of the array is not.

1. For each character, check if it is a duplicate
of already found characters.
2. Skip duplicate characters and update the non duplicate
characters
"""
import unittest
from collections import OrderedDict


def remove_duplicates(input_str):
    return "".join(OrderedDict.fromkeys(input_str))


class Test(unittest.TestCase):
    data_start = ['abcd', 'aaaa', '', 'aaabbb']
    data_end = ['abcd', 'a', '', 'ab']

    def test_remove_duplicates(self):
        for item in zip(self.data_start, self.data_end):
            result = remove_duplicates(item[0])
            self.assertEqual(result, item[1])


if __name__ == "__main__":
    unittest.main()
