"""
1.7 Write an algorithm such that if an element in an MxN matrix is 0,
its entire row and column is set to 0

At first glance, this problem seems easy: just iterate through the matrix and
every time we see a 0, set that row and column to 0 There’s one problem with
that solution though: we will “recognize” those 0s later on in our iteration
and then set their row and column to zero Pretty soon, our entire matrix is 0s!

One way around this is to keep a second matrix which flags the 0 locations We
would then do a second pass through the matrix to set the zeros This would
take O(MN) space

Do we really need O(MN) space? No Since we’re going to set the entire row and
column to zero, do we really need to track which cell in a row is zero?
No We only need to know that row 2, for example, has a zero

The code below implement this algorithm We keep track in two arrays all the
rows with zeros and all the columns with zeros. We then make a second pass
of the matrix and set a cell to zero if its row or
column is zero
"""
import unittest


def setZeros(matrix):
    row = [None] * len(matrix)
    column = [None] * len(matrix[0])
    # Store the row and column index with value 0
    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[0])):
            if matrix[i][j] == 0:
                row[i] = 1
                column[j] = 1

    # Set matrix[i][j] to 0 if either row i or column j
    # has a 0
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if row[i] == 1 or column[j] == 1:
                matrix[i][j] = 0

    return matrix


class Test(unittest.TestCase):
    """
    test setZeros
    """
    input_matrix = [
        [1, 2, 3],
        [4, 0, 6],
        [7, 8, 9]
    ]
    output_matrix = [
        [1, 0, 3],
        [0, 0, 0],
        [7, 0, 9]
    ]
    def test_set_zeros(self):
        result = setZeros(self.input_matrix)
        self.assertEqual(result, self.output_matrix)


if __name__ == "__main__":
    unittest.main()