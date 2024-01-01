// DONE
#include <stddef.h>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// want to find longest path between two leaf nodes.
// idea: the longest path between two leaf nodes must have a root.
// For each node in the tree, we will calculate its left subtree height
// and right subtree height and add these. Call this sum th (total height).
// Do this for every node in the tree. Return the highest value of th.

// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int getHeight(TreeNode *root, int &maxi)
    {
        if (!root)
        {
            return -1;
        }

        int lh = getHeight(root->left, maxi);
        int rh = getHeight(root->right, maxi);

        maxi = std::max(lh + rh + 2, maxi);

        return (1 + std::max(lh, rh));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxi = 0;
        getHeight(root, maxi);
        return maxi;
    }
};