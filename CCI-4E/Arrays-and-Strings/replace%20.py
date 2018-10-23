"""
1.5 Write a method to replace all spaces in a string with %20
"""
import unittest


#
# The LOL pythonic way
#
def urlify(input_str):
    return input_str.replace(" ", "%20")


#
# The non-LOL approach.
#
def primitive_urlify(input_str, str_len):
    list_input_str = list(input_str)
    new_str = ""
    for item in list_input_str:
        if item == ' ':
            new_str += "%20"
        else:
            new_str += item
    return new_str


class Test(unittest.TestCase):
    false_test_data = [("", "s"), ("  ", "%20 2")]
    true_test_data = [("hi there", "hi%20there"),
                      ("d u d e", "d%20u%20d%20e")]

    def test_urlify(self):
        for item in self.false_test_data:
            result = urlify(item[0])
            self.assertNotEqual(result, item[1])
        for item in self.true_test_data:
            result = urlify(item[0])
            self.assertEqual(result, item[1])

    def test_primitive_urlify(self):
        def test_urlify(self):
            for item in self.false_test_data:
                result = primitive_urlify(item[0], len(item[0]))
                self.assertNotEqual(result, item[1])
            for item in self.true_test_data:
                result = urlify(item[0], len(item[0]))
                self.assertEqual(result, item[1])


if __name__ == "__main__":
    unittest.main()
