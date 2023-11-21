#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        // given an array of size n
        // where each element is distinct
        // and is between 0 and n
        // find the missing element.

        // one approach: create a hashmap where every value between 0
        // and n is a key, and its corresponding value is
        // a truth value indicating whether it has been encountered in the
        // array or not

        // create the hashmap, traverse the array and fill the hashmap, and then
        // traverse the hashmap and return the unencountered value
        // time: O(n) + O(n) = O(n)
        // space: O(n)

        // another approach: sort the array and for every consecutive
        // pair of elements, if element two differs from element 1
        // by more than 1, then return (element 2)-1
        // time: O(nlogn) + O(n) = O(nlogn)
        // space: O(1)

        // another approach: calculate the sum of the array
        // and store it in arraySum. Calculate the sum of
        // the numbers from 0 to n and store it in targetSum
        // return targetSum - arraySum
        // time: O(n)
        // space: O(1)
        int n = nums.size();
        int targetSum = n * (n + 1) / 2;
        int arraySum = 0;

        for (int i : nums)
        {
            arraySum += i;
        }

        return targetSum - arraySum;
    }
};