// DONE

// given an integer n, return an array ans of length n+1 such that for each i,
// ans[i] is the number of 1's in the binary representation of i.

// 0 <= n <= 10^5

// n=6, return 2
// n=0, return 0
// n=32
// 10000, return 1

// brute force approach:
// create an algorithm that returns a string binary representation of an integer i O(logn)
// iterate through this string and count the number of ones O(logn)
// execute this algorithm on i = 0...n O(nlogn)

// time complexity: O(nlogn)
// space complexity: O(n)

// an observation

// even numbers: countBits(n) = countBits(n/2)
// n=3, binary=11
// n=6, binary=110
// n=12, binary=1100

// odd numbers: countBits(n) = countBits(n/2) + 1
// n=1, binary=01
// n=2, binary=10
// n=3, binary=11
// n=4, binary= 100
// n=5, binary=101

// better approach:
// create an array of size n+1, called numOnes O(n)
// initialize array[0] = 0
// initialize array[1] = 1

// for i = 2...n: O(n)
//      if i is even:
//            array[i] = array[i/2]
//      if i is odd:
//            array[i] = array[i/2]+1

// return array

// time complexity: O(n)
// space complexity: O(n)

#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> numOnes(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                numOnes[i] = numOnes[i / 2];
            }

            if (i % 2 != 0)
            {
                numOnes[i] = numOnes[i / 2] + 1;
            }
        }

        return numOnes;
    }
};