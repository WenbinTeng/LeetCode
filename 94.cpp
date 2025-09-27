#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> res;

        auto inorder = [&](auto &&self, TreeNode *node) {
            if (node == nullptr)
                return;
            self(self, node->left);
            res.push_back(node->val);
            self(self, node->right);
        };

        inorder(inorder, root);

        return res;
    }
};