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
    bool evaluateTree(TreeNode *root) {
        if (root->left == nullptr || root->right == nullptr) {
            if (root->val == 0)
                return false;
            else
                return true;
        } else {
            if (root->val == 2)
                return evaluateTree(root->left) | evaluateTree(root->right);
            else
                return evaluateTree(root->left) & evaluateTree(root->right);
        }
    }
};