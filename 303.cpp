// DONE

// given an integer array nums, want to handle multiple calls to
// sumRange(left,right), which should return the sum of the elements
// with indices between left and right inclusive

// 1 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5
// 0 <= left <= right < nums.length
// at most 10^4 calls made to sumRange

// examples:
// nums = [1,2,3,4]
// sumRange(0,0) = 1
// sumRange(0,3) = 10
// sumRange(1,3) = 9
// sumRange(0,2) = 6

// brute force approach:

// sumRange(left,right):
//      sum = 0
//      for (i = left...right):
//          sum = sum + nums[i]
//      return sum

// time complexity: O(n) (where n = nums.size())
// space complexity: O(1)

// better approach:
// create another array sumLeft where sumLeft[i]
// is the sum of the first i+1 elements. Fill sumLeft.

// every time sumRange(left,right) is called, return sumLeft[right] - sumLeft[left]

// time complexity: O(1)
// space complexity: O(1)

#include <vector>

class NumArray
{
public:
    std::vector<int> sumLeft;

    NumArray(std::vector<int> &nums)
    {
        sumLeft.resize(nums.size());
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum = sum + nums[i];
            sumLeft[i] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return sumLeft[right];
        }
        return (sumLeft[right] - sumLeft[left - 1]);
    }
};