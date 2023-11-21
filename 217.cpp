#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        // create a hashmap which keeps track of which
        // elements have appeared in the array
        std::unordered_map<int, int> elements;

        // for each element of nums,
        for (int i : nums) // O(n)
        {
            // if it is already in the hashmap, we have found
            // a duplicate
            if (elements.count(i) > 0)
            {
                return true;
            }

            // if it isn't, record it in the hashmap
            elements[i]++;
        }
        return false;
    }
};

// time complexity: O(n)
// space complexity: O(n)