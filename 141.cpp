// DONE
// list has been 0 and 10^4 nodes
// -10^5 <= Node.val <= 10^5

// idea: use two pointers with two different traversal speeds.
// start the slow pointer at head, and the fast pointer at head->next.
// If the two pointers intersect, check if we are at the end of the list.
// If we are not, there is a cycle. If we are, there is no cycle.

// time complexity: O(n), space complexity O(1)

#include <cstddef>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // let slow = head;
        ListNode *slow = head;

        // if slow is null (i.e. the list is empty) return false
        if (slow == NULL)
        {
            return false;
        }

        // let fast = head->next
        ListNode *fast = head->next;

        // while (slow is not in the same position as fast AND fast is not null,)
        /* {
            advance both slow and fast by 1 position
            if possible, advance fast by 1 more position.
        } */

        while (slow != fast && fast != NULL)
        {
            slow = slow->next;

            fast = fast->next;

            if (fast)
            {
                fast = fast->next;
            }
        }

        // if fast is NULL, return false
        // else return true

        if (fast == NULL)
        {
            return false;
        }

        return true;
    }
};