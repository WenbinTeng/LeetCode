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
    int rangeSumBST(TreeNode *root, int low, int high) {
        inorder(root, low, high);
        return res;
    }

  private:
    int res = 0;

    void inorder(TreeNode *node, int low, int high) {
        if (node == nullptr)
            return;

        inorder(node->left, low, high);
        if (node->val >= low && node->val <= high)
            res += node->val;
        inorder(node->right, low, high);
    }
};