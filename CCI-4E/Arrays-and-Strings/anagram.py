"""
1.4 Write a method to decide if two strings are anagrams
or not
"""
import unittest


def anagram(str1, str2):
    return sorted(str1) == sorted(str2)


class Test(unittest.TestCase):
    true_test_data = [("listen", "silent"), ("hithere", "hitheer"),
                      ("", ""), ("None", "oNne")]
    false_test_data = [("hithere", "bro"), ("thi s", "shou ld fail"),
                       ("nogood", "")]

    def test_anagram(self):
        for item in self.true_test_data:
            result = anagram(item[0], item[1])
            self.assertTrue(result)
        for item in self.false_test_data:
            result = anagram(item[0], item[1])
            self.assertFalse(result)


if __name__ == "__main__":
    unittest.main()
