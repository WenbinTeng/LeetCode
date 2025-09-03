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
    bool btreeGameWinningMove(TreeNode *root, int n, int x) {
        TreeNode *xNode = find(root, x);

        int leftSize = getSubtreeSize(xNode->left);
        if (leftSize >= (n + 1) / 2) {
            return true;
        }
        int rightSize = getSubtreeSize(xNode->right);
        if (rightSize >= (n + 1) / 2) {
            return true;
        }

        return n - 1 - leftSize - rightSize >= (n + 1) / 2;
    }

    TreeNode *find(TreeNode *node, int x) {
        if (node == nullptr)
            return nullptr;
        if (node->val == x)
            return node;

        auto ret = find(node->left, x);
        if (ret == nullptr)
            ret = find(node->right, x);

        return ret;
    }

    int getSubtreeSize(TreeNode *node) {
        if (node == nullptr)
            return 0;
        else
            return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }
};