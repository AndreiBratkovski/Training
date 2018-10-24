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


#
# Extra space
#
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


#
# In place
#
def rotate_image_inplace(matrix, m_length):
    for layer in range(0, (m_length // 2)):
        first = layer
        last = m_length - 1 - layer
        for i in range(first, last):
            offset = i - first
            top = matrix[first][i] # save top
            # left -> top
            matrix[first][i] = matrix[last - offset][first]

            # bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset]

            # right -> bottom
            matrix[last][last - offset] = matrix[i][last]

            # top -> right
            matrix[i][last] = top # right <- saved top

    return matrix


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

    def test_rotate_image_inplace(self):
        result = rotate_image_inplace(self.input_matrix,
                                      len(self.input_matrix))
        self.assertEqual(result, self.output_matrix)


if __name__ == "__main__":
    unittest.main()
