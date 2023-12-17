#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        // given an array of n integers
        // where each integer is between 1 and n inclusive
        // return all integers between 1 and n
        // that are not in the array.

        // 1 <= nums.size() , 10^5
        // 1 <= nums[i] <= nums.size()

        // [5,5,5,5,5,6,7]
        // return [1,2,3,4]

        // approach 1
        // let n = nums.size() O(1)
        // let output_array = new vector() O(1)

        // have a set which contains the numbers 1 up to nums.size() O(n)
        // for each num in nums: // O(n)
        // pop num from the set // O(logn)

        // for each element in set: // O(n)
        // push element into output_array // O(1)

        // return output_array // O(1)

        // time: O(nlogn)
        // space: O(n)

        // approach 2
        // let n = nums.size() O(1)
        // let output_array = new vector() O(1)

        // have a hashmap which maps integers to booleans
        // for each num=1...n:
        // hashmap[n] = false

        // for each num in nums:
        // hashmap[num] = true

        // for each num=1...n:
        // if hashmap[num] == false:
        // push num to output_array

        // return output array

        // time complexity: O(n)
        // space: O(n)

        // we choose to go with approach 2

        // n = nums.size()
        int n = nums.size();

        // output array
        std::vector<int> output_array;

        // have a hashmap which maps integers to booleans
        std::unordered_map<int, bool> appearsInNums;

        // for each num=1...n:
        // hashmap[n] = false
        for (int i = 1; i <= n; ++i)
        {
            appearsInNums[i] = false;
        }

        // for each num in nums:
        // hashmap[num] = true
        for (int num : nums)
        {
            appearsInNums[num] = true;
        }

        // for each num=1...n:
        // if hashmap[num] == false:
        // push num to output_array
        for (int i = 1; i <= n; ++i)
        {
            if (appearsInNums[i] == false)
            {
                output_array.push_back(i);
            }
        }

        // return output array
        return output_array;

        // time complexity: O(n)
        // space: O(n)
    }
};