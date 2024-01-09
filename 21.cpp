// given two sorted lists, return the sorted merged list.

// example1: list1 = [1->2->3], list2 = [1->-3], output = [1,1,2,3,3]
// example2: list1 = [], list2 = [4,5,6], output = [4,5,6]

// one approach: iterate through both lists and append each node's value
// to a vector array 'values'. Sort values. Generate a linked list
// from values and return it.
// time complexity: O(m+n)
// space complexity: O(m+n)

// better approach:
// use two pointers, ptr1=list1 and ptr2=list2.
// While neither is null:
//         take the node of lesser value from ptr1 and ptr2
//         append it onto a new list, list3. Advance the chosen pointer.
// finally, append all remaining nodes onto list3
// return list3.
// time complexity: O(m+n)
// space complexity: O(m+n)

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ptrs for list1 and list2
        auto ptr1 = list1;
        auto ptr2 = list2;

        // output list
        ListNode *list3 = new ListNode;
        ListNode *ptr3 = list3;

        // build merged list until either list1 or list2
        // is empty
        while (ptr1 && ptr2)
        {
            if (ptr1->val < ptr2->val)
            {
                ptr3->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else
            {
                ptr3->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }

            ptr3 = ptr3->next;
        }

        // append remaining nodes

        if (ptr1)
        {
            ptr3->next = ptr1;
        }

        if (ptr2)
        {
            ptr3->next = ptr2;
        }

        return list3->next;
    }
};