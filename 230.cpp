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
        return root == nullptr ? 0 : inorder(root, k);
    }

  private:
    int inorder(TreeNode *node, int &cnt) {
        if (node == nullptr)
            return -1;
        else {
            int a = inorder(node->left, cnt);
            if (a != -1)
                return a;

            if (--cnt == 0)
                return node->val;

            int b = inorder(node->right, cnt);
            if (b != -1)
                return b;

            return -1;
        }
    }
};