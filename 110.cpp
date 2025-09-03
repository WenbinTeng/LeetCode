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
    bool isBalanced(TreeNode *root) {
        checkHeight(root);
        return res;
    }

  private:
    bool res = true;

    int checkHeight(TreeNode *node) {
        if (node == nullptr || !res)
            return 0;

        int left = checkHeight(node->left);
        int right = checkHeight(node->right);

        res = res && std::abs(left - right) <= 1;

        return std::max(left, right) + 1;
    }
};