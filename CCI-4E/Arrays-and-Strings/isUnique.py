"""
1.1 Implement an algorithm to determine if a string has all unique
characters.What if you can not use additional data structures?
"""

# For simplicity, assume char set is ASCII (if not, we need to increase
# the storage size. The rest should be the same). NOTE: this is a great thing
# to point out to your interviewer!

import unittest


def is_unique_chars_2(input_str):
    char_set = [0] * 256
    for i in range(0, len(input_str)):
        val = ord(input_str[i])
        if char_set[val]:
            return False
        char_set[val] = True
    return True


class Test(unittest.TestCase):
    dataT = ['abcd', 's4fad', '']
    dataF = ['23ds2', 'hb 627jh=j ()']

    def test_unique(self):
        # true check
        for test_string in self.dataT:
            actual = is_unique_chars_2(test_string)
            self.assertTrue(actual)
        # false check
        for test_string in self.dataF:
            actual = is_unique_chars_2(test_string)
            self.assertFalse(actual)


if __name__ == "__main__":
    unittest.main()
