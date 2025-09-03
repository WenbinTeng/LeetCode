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
    int minDiffInBST(TreeNode *root) {
        inorder(root);
        return res;
    }

  private:
    int val = 0x3f3f3f3f;
    int res = 0x3f3f3f3f;

    void inorder(TreeNode *node) {
        if (node == nullptr)
            return;

        inorder(node->left);

        res = std::min(res, std::abs(node->val - val));
        val = node->val;

        inorder(node->right);
    }
};