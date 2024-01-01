// given an integer array nums with n elements, and an integer k
// find the length-k subarray with the highest average value.

// -10^5 < n < 10^5
// 1 <= k <= n <= 10^5
// -10^4 <= n[i] <= 10^4

// [5,9,1,0,2]
// n = 5
// k = 2
// average of 5,9 is 7
// average of 9,1 is 5
// average of 1,0 is 1/2
// average of 0,2 is 1

// returned answer: 7

// number of possible windows = n-k+1

// approach: traverse the array with a size-k window that slides from left to right
// on the first iteration, let sum = <sum of window elements>, and let
// maxAverage = <average of window elements>

// on every subsequent iteration, increase the start index of the window and the
// end index of the window. decrease the sum by the value of the former first index
// and increase the sum by the value of the current end index. Let
// maxAverage = max(sum/k,maxAverage).

// return maxAverage

// time complexity: O(n) since we have n-k+1 windows to consider
// and each window requires one subtraction, one addition, one division
// and one call to max().

// space complexity: O(1).

#include <algorithm>
#include <vector>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        double sum = 0;
        double average = 0;
        double maxAverage;
        int i = 0;
        int j = k - 1;

        for (int idx = i; idx <= j; ++idx)
        {
            sum = sum + nums[idx];
            maxAverage = sum / k;
        }

        for (int i = 0; i < n - k; ++i)
        {
            ++j;
            sum -= nums[i];
            sum += nums[j];
            maxAverage = std::max(sum / k, maxAverage);
        }

        return maxAverage;
    }
};