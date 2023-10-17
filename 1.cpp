#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // basic idea: in a hashmap, map each value to an
        // index it can be found at (O(n) time, O(n) space). Then,
        // scan the array and for each element 'e', check if target - e
        // has a corresponding index in the hashmap (O(n) time).
        // if it does, return hashmap[e] and the index at which e
        // is located.

        // If IndexOfValue[i] = j, then
        // nums[j] = i. We won't have any problems
        // with collisions since each input
        // only has one solution anyway.
        std::unordered_map<int, int> IndexOfValue;

        for (size_t i = 0; i < nums.size(); i++) // O(n)
        {
            IndexOfValue[nums[i]] = i; // O(1)
        }

        for (int i = 0; i < nums.size(); i++) // O(n)
        {
            if (IndexOfValue.count(target - nums[i]) > 0 && i != IndexOfValue[target - nums[i]])
            {
                std::vector<int> soln(2);                   // O(1)
                soln = {IndexOfValue[target - nums[i]], i}; // O(1)
                return soln;                                // O(1)
            }
        }

        return {};
    }
};

// overall, O(n) time and O(n) space. Some other solutions:
// 1. for each i < nums.size(), check if nums[i] + nums[j] where i < j < nums.size
// adds up to target. This would be O(n^2) time and O(1) space

// 2. sort the array and for each element 'e' do a binary search for
// target - e. This would be O(nlogn) time and O(1) space.

// our solution sacrifices some space for better speed, but
// 2. might be the desired solution if we would rather sacrifice
// speed for space.