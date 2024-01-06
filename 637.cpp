// task: Given the root of a binary tree,
// return the average value of the nodes on each level
// in the form of an array.

// idea: bfs, except our queue will consist of pairs of the
// form <TreeNode*, int>. The second element will be
// the current layer. On each iteration of the BFS,
// we will save the queue front into a variable 'front',
// and then push <front.first->left/right,front.second+1> into
// the queue. Count number of nodes and sum of values
// for each layer, resetting both counters at the end of
// each layer.

// time complexity: O(n) since it's just BFS with a few extra
// constant-time operations on each iteration

// space complexity: O(n) since we need a vector whose size
// is the number of levels in the tree, and in the worst case
// (i.e. a list), the number of levels will equal the number of nodes.

#include <vector>
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
    std::vector<double> averageOfLevels(TreeNode *root)
    {
        // use a pair queue instead of a TreeNode queue -
        // this allows us to link each node with its layer.
        std::queue<std::pair<TreeNode *, int>> nodeQ;
        std::vector<double> averages;

        // variables to count the number of nodes
        // and the sum of their values in each layer.
        // Reset for each new layer.
        double nodeCount = 0;
        double valSum = 0;

        // compare the current node's layer to this value
        // to detect when a new layer has started
        int currentLayer = 0;

        nodeQ.push({root, 0});

        while (!nodeQ.empty())
        {
            auto frontNode = nodeQ.front().first;
            auto frontLayer = nodeQ.front().second;

            nodeQ.pop();

            // if we've reached a new layer,
            // push back the average and start calculating
            // an average for a new layer
            if (frontLayer != currentLayer)
            {
                averages.push_back(valSum / nodeCount);
                valSum = 0;
                nodeCount = 0;
                currentLayer++;
            }

            valSum += frontNode->val;
            nodeCount++;

            if (frontNode->left)
            {
                nodeQ.push({frontNode->left, frontLayer + 1});
            }

            if (frontNode->right)
            {
                nodeQ.push({frontNode->right, frontLayer + 1});
            }
        }

        // the end of the last layer won't be detected, so
        // we'll have to push the average ourselves.
        averages.push_back(valSum / nodeCount);
        return averages;
    }
};