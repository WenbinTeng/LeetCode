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
    int diameterOfBinaryTree(TreeNode *root) {
        int res = 0;

        auto postorder = [&](auto &&self, TreeNode *node) -> int {
            if (node == nullptr)
                return 0;
            int lh = self(self, node->left);
            int rh = self(self, node->right);
            res = std::max(res, lh + rh + 1);
            return std::max(lh, rh) + 1;
        };

        postorder(postorder, root);

        return res - 1;
    }
};