// given the roots of two binary trees p and q, return true if they are the same tree
// and false otherwise.

// each tree has between 0 and 100 nodes inclusive.

// one idea: perform some traversal method (eg preorder) on both trees simultaneously
// and at any given point, the values of the two nodes being processed should
// be equal.
// time complexity: O(min(m,n)) since if one tree runs out of nodes
// the process stops
// space complexity: O(min(m,n)) for same reason.

// a better idea: use isSameTree as a recursive function which just checks
// if two nodes are equal and calls itself on their two left children
// and two right children recursively and then returns an AND of
// isSameTree performed on every pair of nodes.

// pseudocode:
// function isSameTree(p,q):
//         base case: is one of the nodes null?
//                 if (!p || !q): return (p == q)
//         regular case:
//                return isSameTree(p->left,q->left) AND isSameTree(p>right,q->right)
//                                                 AND p->val == q->val

// time complexity: O(max(m,n)) since the process stops once we run out of nodes
// space complexity: O(max(m,n))

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        //         base case: is one of the nodes null?
        //                 if (!p || !q): return (p == q)

        if (!p || !q)
            return (p == q);

        //         regular case:
        //                return isSameTree(p->left,q->left) AND isSameTree(p>right,q->right)
        //                                                 AND p->val == q->val

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }
};