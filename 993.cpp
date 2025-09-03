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
    bool isCousins(TreeNode *root, int x, int y) {
        preorder(root, 0, x, y);
        return xDepth == yDepth && !sameFather;
    }

  private:
    int xDepth = -1;
    int yDepth = -1;
    bool sameFather = false;

    void preorder(TreeNode *node, int depth, int x, int y) {
        if (node == nullptr)
            return;

        if (node->val == x)
            xDepth = depth;
        if (node->val == y)
            yDepth = depth;

        if (xDepth >= 0 && yDepth >= 0)
            return;

        preorder(node->left, depth + 1, x, y);
        preorder(node->right, depth + 1, x, y);

        if (node->left != nullptr && node->right != nullptr) {
            if (node->left->val == x && node->right->val == y ||
                node->left->val == y && node->right->val == x) {
                sameFather = true;
            }
        }
    }
};