// given an n x n matrix, rotate it 90 degrees clockwise inplace.

// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

// example: [1 2 3]
//          [4 5 6]
//          [7 8 9]

// output: [7 4 1]
//         [8 5 2]
//         [9 6 3]

// approach: want to fin some sequence of simple transformations
// that will correspond to a 90 degree rotation.

// notice that if we do a horizontal reflection on our example input we get
// [7 8 9]
// [4 5 6]
// [1 2 3]

// and this only differs by a reflection along the diagonal from our desired output.

// so, the approach is:
// reflect horizontally
//  requires us to swap ~n^2/2 pairs of elements
// reflect along diagonal
//  requires us to swap ~n^2/2 pairs of elements.

// tc: each swap is constant time, so overall O(n^2)
// sc: O(1)

#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        int n = matrix.size();

        // reflect horizontally
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        // reflect along diagonal
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};