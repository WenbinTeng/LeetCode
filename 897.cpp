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
    TreeNode *increasingBST(TreeNode *root) {
        head = tail = new TreeNode();
        inorder(root);
        return head->right;
    }

  private:
    TreeNode *head;
    TreeNode *tail;

    void inorder(TreeNode *node) {
        if (node == nullptr)
            return;

        inorder(node->left);
        tail->right = new TreeNode(node->val);
        tail = tail->right;
        inorder(node->right);
    }
};