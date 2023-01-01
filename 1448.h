#include <algorithm>

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
    int goodNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        preorder(root, root->val);
        return res;
    }

private:
    int res = 0;

    void preorder(TreeNode *node, int maxVal) {
        if (node == nullptr)
            return;

        if (node->val >= maxVal)
            ++res;
        preorder(node->left, std::max(maxVal, node->val));
        preorder(node->right, std::max(maxVal, node->val));
    }
};