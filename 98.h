#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return root == nullptr ? false : inorder(root, -LLONG_MAX - 1, LLONG_MAX);
    }

private:
    bool inorder(TreeNode *node, long long lower, long long upper) {
        if (node == nullptr)
            return true;

        bool res = true;

        res = res && inorder(node->left, lower, node->val);
        res = res && node->val > lower && node->val < upper;
        res = res && inorder(node->right, node->val, upper);

        return res;
    }
};