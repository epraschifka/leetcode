#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        // if prices is decreasing, the answer is zero.

        // if prices has an increasing subsequence, the
        // answer is greater than zero.

        // want to find the longest increasing subsequence
        // and calculate the difference between its last and first elmeent.

        // idea: calculate a sort of "running difference",
        // starting at the first element.

        // in example 1, our difference would initially be zero (7-7),
        // and then we would reset our minimum upon reaching 1 since
        // it is smaller than the current minimum.

        // Then, our difference would be zero (1-1), and then
        // would increase to 4 (5-1). 2 (3-1) is less than
        // 4 so we would ignore this difference, but
        // 5 (6-1) is greater than 4 so this would become our new
        // max difference. Lastly, 3 (4-1) is less than 5 so our final
        // answer would be 5.

        // so, we need a minimum variable, and a max_diff variable
        int minimum = prices[0];
        int max_diff = 0;

        for (int price : prices) // O(n)
        {
            minimum = std::min(price, minimum);             // O(1)
            max_diff = std::max(max_diff, price - minimum); // O(1)
        }

        return max_diff;

        // overall, O(n) time and O(1) space
    }
};