// given an integer array nums, move all zeros to the end of the array while maintaining
// relative order of all other elements.

// 1 <= nums.size <= 10^4
// no restriction on number of zeros

// example: [1,0,2,0,3], output: [1,2,3,0,0,0]
// example: [1,0,0], output: [1,0,0]

// brute force solution: create an int variable called 'zeros', initiaily set to 0. Create an array
// called 'output'. Traverse the input array. For each number we encounter,
// if the number is non-zero, push it to output. If it is zero, increase zeros by 1.
// Once the input array has been traversed, push 0 onto the output array 'zeros' times.
// tc: O(n)
// sc: O(n)

// a better solution: '
// create an int variable called 'nZeros', initially set to 0.
// Traverse nums. For each number we encounter,
// if the number is non-zero, set nums[i-nZeros] = nums[i].
// If the number is zero, set nZeros = nZeros+1
// set the last nZeros elements to zero.

// tc: O(n)
// sc: O(1)

#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int nZeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != 0)
            {
                nums[i - nZeros] = nums[i];
            }
            else
            {
                ++nZeros;
            }
        }

        for (int i = 0; i < nZeros; ++i)
        {
            nums[n - 1 - i] = 0;
        }
    }
};