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
    int maxDepth(TreeNode *root) { return searchHeight(root, 0); }

  private:
    int searchHeight(TreeNode *node, int h) {
        return node == nullptr ? h
                               : std::max(searchHeight(node->left, h + 1),
                                          searchHeight(node->right, h + 1));
    }
};