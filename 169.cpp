// given an array of size n, return the element that appears more than n/2 times
// (this element is guaranteed to exist).

// the array can be between 1 and 5*10^4 elements long
// each elements can be anywhere between -10^9 and 10^9

// examples:
// nums = [1], return 1
// nums = [1,2,2], return 2
// nums = [5,5,5], return 5

// brute force: use a hashmap to track the frequency of each element in the array
// return the element in the hashmap with the highest frequency
// tc: O(n)
// sc: O(n)

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> frequency;

        for (int num : nums)
        {
            ++frequency[num];
        }

        int majority_elem = 0;

        for (auto itr = frequency.begin(); itr != frequency.end(); ++itr)
        {
            if (itr->second > frequency[majority_elem])
            {
                majority_elem = itr->first;
            }
        }

        return majority_elem;
    }
};