"""
1.6 Given an image represented by an NxN matrix, where each pixel in the image
is 4 bytes, write a method to rotate the image bey 90 degrees. Can you do this
in place?

Input:
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
]
Output:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
"""
import unittest
from collections import deque


def rotate_image(matrix):
    results = []
    m_length = len(matrix)
    # we use N for both loops because we are looking at
    # this from a column and row perspective rather than
    # nested arrays
    for col in range(0, m_length):
        inner = deque([])
        for row in range(0, m_length):
            item = matrix[row][col]
            inner.appendleft(item)
        results.append(list(inner))
    return results


class Test(unittest.TestCase):
    input_matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    output_matrix = [
        [7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]
    ]

    def test_rotate_image(self):
        result = rotate_image(self.input_matrix)
        self.assertEqual(result, self.output_matrix)


if __name__ == "__main__":
    unittest.main()
