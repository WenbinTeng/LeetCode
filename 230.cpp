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
    int kthSmallest(TreeNode *root, int k) {
        int res = 0;
        auto inorder = [&](auto &&self, TreeNode *node, int k) -> int {
            if (node == nullptr)
                return 0;
            int lh = self(self, node->left, k);
            if (lh == k - 1) {
                res = node->val;
            }
            int rh = self(self, node->right, k - lh - 1);
            return lh + rh + 1;
        };
        inorder(inorder, root, k);
        return res;
    }
};