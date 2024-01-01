// given a linked list, return its middle node. If the list has
// an even number of nodes, return the right-middle node.

// [1,2,3] => Node(2)
// [4,5,6,7] => Node(6)

// 1 <= list size <= 100

// brute force:
// iterate through the list with a counter initialized to zero.
// For each node we encounter, increment counter such that
// by the time we've iterated through the list, counter equals
// the number of nodes in the list

// initialize another counter 'counter2'. Iterate through the list
// again, incrementing counter2 in the same way. When counter2 = counter/2
// return the current node
// time complexity: O(n)
// space complexity: O(1)

// a simpler solution:
// 1. initialize two pointers slow and fast both equal to head.
// 2. while fast is not null and fast next is not null, slow moves
// forward one position, fast moves forward two positions.
// 3. return slow.

// time complexity: O(n)
// space complexity: O(1)

#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        // 1. initialize two pointers slow and fast both equal to head.
        ListNode *slow = head;
        ListNode *fast = head;

        // 2. while fast is not null and fast next is not null, slow moves
        // forward one position, fast moves forward two positions.
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 3. return slow.
        return slow;
    }
};