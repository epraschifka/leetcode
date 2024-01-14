// given a binary tree, find its minimum depth. The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// number of nodes in the tree is between 0 and 10^5

// example 1:
//         1
//     2       3
//  4    5

// output: 2

// example 2:
// NULL
// output: 0

// example 3:
//     1
//   2
// output: 1

// idea: do BFS. On each 'layer' of the BFS, increment counter by 1.
// If we encounter a node with no children, stop the BFS and return counter.

// let nodeQueue = queue<pair<TreeNode*,int>>
// let counter = 1
// add root to nodeQueue

// while nodeQueue is nonempty:
//     let top = nodeQueue.top
//     pop top element from nodeQueue
//     if top->layer != currentLayer, counter++
//     if top->left and top->right both null, return counter
//     if top->left is not null, push {top->left,counter+1} into nodeQueue
//     if top->right is not null, push {top->rught,counter+1} into nodeQueue

// time complexity: O(n) (BFS)
// space complexity: O(n) (BFS)

#include <queue>

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
    int minDepth(TreeNode *root)
    {
        // check if root is null
        if (!root)
        {
            return 0;
        }

        // let nodeQueue = queue<pair<TreeNode*,int>>
        std::queue<std::pair<TreeNode *, int>> nodeQueue;

        // let counter = 1
        int counter = 1;

        // add root to nodeQueue
        nodeQueue.push({root, counter});

        // while nodeQueue is nonempty:
        while (!nodeQueue.empty())
        {
            //     let top = nodeQueue.front
            auto top = nodeQueue.front();

            //     pop top element from nodeQueue
            nodeQueue.pop();

            //     if top->layer != counter, counter++
            if (top.second != counter)
            {
                ++counter;
            }

            //     if top->left and top->right both null, return counter
            if (!top.first->left && !top.first->right)
            {
                return counter;
            }

            //     if top->left is not null, push {top->left,counter+1} into nodeQueue
            if (top.first->left)
            {
                nodeQueue.push({top.first->left, counter + 1});
            }

            //     if top->right is not null, push {top->rught,counter+1} into nodeQueue
            if (top.first->right)
            {
                nodeQueue.push({top.first->right, counter + 1});
            }
        }

        return counter;
    }
};