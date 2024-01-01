<<<<<<< HEAD
// given the head of an integer linked list, return true if it is palindromic
// and false otherwise.

// a suboptimal approach:
// 1. iterate through list and push values into an integer array called "values"
// 2. let "values_reversed" = reverse(values)
// 3. iterate through values. If values[i] == values_reversed[i] for all i,
// return true. Otherwise return false.

// time complexity: step 1 is linear time (one iteration through list), step 2
// is linear time (reverse), and step 3 is linear too (iterate through values again),
// so O(n) time overall

// space complexity: have to create two arrays. The length of both arrays is
// the length of the list, so O(n) space used.

// a better approach!

// 1. iterate through the list with a slow and fast pointer until either
// fast is null or fast->next is null
// 2. if fast->next is null then the list has an odd number of nodes,
// so increment slow by one position.
// 3. Use a helper function to reverse the list starting at "slow", and return
// slow as the new head of the reversed list
// 4. check that the ith value of the list rooted at head equals
// the ith value of the list rooted at slow. Return true if yes, false if no.

// time complexity: step 1 is just a single iteration so O(n) time.
// step 2 is constant time. The helper function in step 3 is linear
// so step 3 is O(n). Step 4 requires us to iterate through the two half-lists
// so step 4 is O(n). Overall, O(n) time.

// space complexity: we use a constant amount of space so O(1).

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
    // start by creating our reverse function.
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        // 1. iterate through the list with a slow and fast pointer until either
        // fast is null or fast->next is null.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. if fast->next is not null then the list has an odd number of nodes,
        // so increment slow by one position.
        if (fast)
        {
            slow = slow->next;
        }

        // 3. Use a helper function to reverse the list starting at "slow", and return
        // slow as the new head of the reversed list.
        slow = reverse(slow);

        // 4. check that the ith value of the list rooted at head equals
        // the ith value of the list rooted at slow. Return true if yes, false if no.
        while (slow != NULL && head != NULL)
        {
            if (slow == NULL || head == NULL)
            {
                return false;
            }

            if (slow->val != head->val)
            {
                return false;
            }

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
=======
// given the head of an integer linked list, return true if it is palindromic
// and false otherwise.

// a suboptimal approach:
// 1. iterate through list and push values into an integer array called "values"
// 2. let "values_reversed" = reverse(values)
// 3. iterate through values. If values[i] == values_reversed[i] for all i,
// return true. Otherwise return false.

// time complexity: step 1 is linear time (one iteration through list), step 2
// is linear time (reverse), and step 3 is linear too (iterate through values again),
// so O(n) time overall

// space complexity: have to create two arrays. The length of both arrays is
// the length of the list, so O(n) space used.

// a better approach!

// 1. iterate through the list with a slow and fast pointer until either
// fast is null or fast->next is null
// 2. if fast->next is null then the list has an odd number of nodes,
// so increment slow by one position.
// 3. Use a helper function to reverse the list starting at "slow", and return
// slow as the new head of the reversed list
// 4. check that the ith value of the list rooted at head equals
// the ith value of the list rooted at slow. Return true if yes, false if no.

// time complexity: step 1 is just a single iteration so O(n) time.
// step 2 is constant time. The helper function in step 3 is linear
// so step 3 is O(n). Step 4 requires us to iterate through the two half-lists
// so step 4 is O(n). Overall, O(n) time.

// space complexity: we use a constant amount of space so O(1).

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
    // start by creating our reverse function.
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        // 1. iterate through the list with a slow and fast pointer until either
        // fast is null or fast->next is null.
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. if fast->next is not null then the list has an odd number of nodes,
        // so increment slow by one position.
        if (fast)
        {
            slow = slow->next;
        }

        // 3. Use a helper function to reverse the list starting at "slow", and return
        // slow as the new head of the reversed list.
        slow = reverse(slow);

        // 4. check that the ith value of the list rooted at head equals
        // the ith value of the list rooted at slow. Return true if yes, false if no.
        while (slow != NULL && head != NULL)
        {
            if (slow == NULL || head == NULL)
            {
                return false;
            }

            if (slow->val != head->val)
            {
                return false;
            }

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
>>>>>>> 996054cf3486d0e53b41724047a8de64a87b3378
};