#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        return travel(root, std::min(p->val, q->val), std::max(p->val, q->val));
    }

private:
    TreeNode *travel(TreeNode *node, int i, int j) {
        if (node == nullptr)
            return nullptr;

        if (i <= node->val && j >= node->val) {
            return node;
        } else if (i <= node->val && j <= node->val) {
            return travel(node->left, i, j);
        } else if (i >= node->val && j >= node->val) {
            return travel(node->right, i, j);
        }

        return nullptr;
    }
};