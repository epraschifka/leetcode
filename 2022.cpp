// given a 1d array, convert it into a 2d array of size m x n and return the result, or return
// an empty 2d array if this is not possible.

// 1 <= original.size() <= 5 * 10^4
// 1 <= m,n <= 4 * 10^4

// example: original = [1,2,3,4], m = 2, n = 2
// output = [1 2]
//          [3 4]

// example: original = [1 2 3], m = 4, n = 1
// output = []

// brute force: If the length of original is not equal to m x n, return [].
// initialize two counters i,j = 0 and a 2d output array of size m x n.

// Iterate through original with index 'idx'. Set output[i][j] = original[idx].
// after each element, increase j by 1. On the first element of each row after the first row,
// reset j to 0 and increase i by 1.

// tc: O(m x n) (have to initialize array of size m x n)
// sc: O(m x n) (have to initialize array of size m x n)

#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int> &original, int m, int n)
    {
        std::vector<std::vector<int>> output;
        int mn = m * n;

        if (original.size() != mn)
        {
            return output;
        }

        int i = 0;
        int j = 0;
        output.resize(m, std::vector<int>(n));

        for (int idx = 0; idx < mn; ++idx)
        {
            if (idx != 0 && idx % n == 0)
            {
                j = 0;
                ++i;
            }

            output[i][j] = original[idx];
            ++j;
        }

        return output;
    }
};