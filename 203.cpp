// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// list size is between 0 and 10^4 inclusive

// example1: head = [4,8,2,8,9,0], val = 8, output = [4,2,9,0]
// example2: head = [], val = 6, output = []
// example3: head = [8,3,8], val = 8, output = 6

// brute force: iterate through list and push every
// node's val not equal to val into an integer vector.
// Iterate through the integer vector, and generate the new
// linked list from this vector.

// time complexity: O(n) since we need to iterate through
// a list of size n and a vector of size n.
// space complexity: O(n) since we need a vector of size n.

// a better approach:
// 1. move head forwards until it's a legal node.
// 2. set dummy = head.
// 3. while dummy is not null:
//              if dummy->next is illegal:
//                          delete dummy->next
//              else move dummy forward
// 4. return head

// time complexity: Dummy starts at head, and we have
// a while loop which repeats so long as dummy is not null.
// On each iteration of the while
// loop we either delete a node or move dummy forward.
// The loop therefore ends if dummy is moved forward n times,
// or if n nodes are deleted. Therefore time complexity is less than
// 2n, so time complexity is O(n)

// space complexity: O(1)

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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 1. move head forwards until it's a legal node.
        while (head && head->val == val)
        {
            head = head->next;
        }

        //  2. set dummy = head.
        ListNode *dummy = head;

        // 3. while dummy is not null:
        //       if dummy->next is illegal:
        //               delete dummy->next
        //       else move dummy forward

        while (dummy)
        {
            if (dummy->next && dummy->next->val == val)
            {
                dummy->next = dummy->next->next;
            }
            else
                dummy = dummy->next;
        }

        // 4. return head
        return head;
    }
};