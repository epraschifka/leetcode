#include <vector>
#include <string>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// use a recursive function f which consistently updates a nodepath string passed by value.
// for each node encountered, add it to the nodepath string and call f on both
// its children

// f will also take a string vector nodepaths by reference. Once we reach a leaf node
// push back nodepath into nodepaths.

// time complexity: O(N)
// space complexity: O(N)

class Solution
{
public:
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        // create vector which will store nodepaths
        std::vector<std::string> nodepaths;

        // create node path variable and add root's value to it
        std::string nodepath;
        nodepath += std::to_string(root->val);

        // if root is the only node, return nodepath
        if (root->left == NULL && root->right == NULL)
        {
            nodepaths.push_back(nodepath);
            return nodepaths;
        }

        // otherwise, call f on roots left and right children recursively
        f(root->left, nodepath, nodepaths);
        f(root->right, nodepath, nodepaths);
        return nodepaths;
    }

    void f(TreeNode *root, std::string nodepath, std::vector<std::string> &nodepaths)
    {
        if (!root)
        {
            return;
        }

        // since we're not at a null node, add
        // current node to our nodepath
        nodepath += "->" + std::to_string(root->val);

        // if we're at a leaf node, we can add our path to nodepaths and stop here.
        if (root->left == NULL && root->right == NULL)
        {
            nodepaths.push_back(nodepath);
            return;
        }

        // follow left child path
        f(root->left, nodepath, nodepaths);

        // follow right child path
        f(root->right, nodepath, nodepaths);

        return;
    }
};