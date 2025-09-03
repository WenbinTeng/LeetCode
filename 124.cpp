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
    int maxPathSum(TreeNode *root) {
        searchPath(root);
        return maxVal;
    }

  private:
    int maxVal = -INT_MAX - 1;

    int searchPath(TreeNode *node) {
        if (node == nullptr)
            return 0;

        int left = std::max(0, searchPath(node->left));
        int right = std::max(0, searchPath(node->right));

        maxVal = std::max(maxVal, node->val + left + right);

        return node->val + std::max(left, right);
    }
};