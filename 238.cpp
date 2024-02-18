// Given an array nums, return an array answer where answer[i] is the product of all
// the elements of nums except nums[i].

// 2 <= nums.size() <= 10^5
// -30 <= nums[i] <= 30

// example: [1,2,3,4] => output: [24,12,8,6]
// example: [1,2] => output: [2,1]

// brute force approach:
// for each element of nums, do a linear scan with a product
// variable initialized to 1 to calculate the product of the other
// elements. Create an array called answer and fill answer with these products.

// tc: O(n^2)
// sc: O(n)

// better approach: create two arrays 'left' and 'right'  where
// left[i] is the product of every element to the left of nums[i],
// and right[i] is the product of every element to the right of nums[i].

// to find answer[i], calculate left[i] * right[i].

// tc: O(n)
// sc: O(n)

#include <vector>

class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> left(n, 1);
        std::vector<int> right(n, 1);
        std::vector<int> answer(n);

        int product = 1;

        for (int i = 0; i < n; ++i)
        {
            left[i] = product;
            product = product * nums[i];
        }

        product = 1;

        for (int i = n - 1; i >= 0; --i)
        {
            right[i] = product;
            product = product * nums[i];
        }

        for (int i = 0; i < n; ++i)
        {
            answer[i] = left[i] * right[i];
        }

        return answer;
    }
};