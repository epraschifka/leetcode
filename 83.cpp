// DONE

// given a sorted list, remove all nodes which have duplicate values, such
// that each element appears only once.

// 0 <= list size <= 300
// -100 <= node->val <= 100

// one idea: iterate through the list, for each node we encounter
// store the node's value in a set. After we've iterated through the list,
// we'll have a set of all unique values in the list. Iterate through the set
// and create a new list which consists of one node for each value in the set.
// return this new set

// time complexity: iterating through the list takes O(n) time. For each
// element we encounter we have to insert it, taking O(logn) time.
// After the iteration is complete, we iterate through the set, taking O(n)
// time, and push back each value into a new set.
// O(nlogn + n) = O(nlogn)

// space complexity: O(n).

// we would like an in-place solution. Idea: iterate through the list
// with a slow and fast pointer. While their values are equal, move the fast
// pointer forward. If they're not equal, set slow->next = fast
// repeat this until we've reached the end of the list.

// While fast is not null:
//          if fast->val == slow->val:
//                  move fast forward by one position
//          else:
//              slow->next = fast
//              slow = slow->next
// slow->next = fast
// return head

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            if (slow->val == fast->val)
            {
                fast = fast->next;
            }
            else
            {
                slow->next = fast;
                slow = slow->next;
            }
        }
        slow->next = fast;
        return head;
    }
};