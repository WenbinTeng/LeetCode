#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int maxDepth(TreeNode *root) {
        auto getDepth = [](auto &&self, TreeNode *node, int h) -> int {
            return node == nullptr ? h
                                   : std::max(self(self, node->left, h + 1),
                                              self(self, node->right, h + 1));
        };
        return getDepth(getDepth, root, 0);
    }
};