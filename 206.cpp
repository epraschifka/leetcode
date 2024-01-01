// goal: reverse a linked list

// use a recursive function recReverse which takes in two ListNode* parameters
// curr and prev, representing the current and previous nodes respectively.
// recReverse does the following:
// 1. If curr is NULL, then return prev
// 2. save curr->next into a variable 'next'
// 3. set curr->next to prev
// 4. call recReverse(next,curr)

// examples:
// input: NULL
// return recReverse(NULL,NULL)
//         return NULL; CORRECT

// input: [1]
// return recReverse(Node(1),NULL)
//         next = curr->next = NULL
//         Node(1)->next = NULL
//         return recReverse(NULL,Node(1))
//             return Node(1) CORRECT

// input: [1->2]
// return recReverse(Node(1),NULL)
//         next = Node(2)
//         Node(1)->next = NULL
//         return recReverse(Node(2),Node(1))
//                 next = NULL
//                 Node(2)->next = Node(1)
//                 return recReverse(NULL,Node(2))
//                         return Node(2) CORRECT

// time complexity: recReverse is called n+1 times. Each call results in
// 1-4 constant operations, so O(n)
// space complexity: most calls of recReverse will result in the creation
// of a variable 'next', so each stack frame will be height 1. Furthermore,
// the max depth of the call stack will be N, since we initially call
// recReverse with curr = head, recReverse moves curr one step
// forward on each subsequent call of itself, and the function
// only terminates once curr = NULL so this will take N concurrent calls,
// so O(n).

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
    ListNode *recReverse(ListNode *curr, ListNode *prev)
    {
        if (curr == NULL)
        {
            return prev;
        }

        ListNode *next = curr->next;
        curr->next = prev;
        return recReverse(next, curr);
    }

    ListNode *reverseList(ListNode *head)
    {
        return recReverse(head, NULL);
    }
};