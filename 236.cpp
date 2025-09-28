#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *res;

        auto dfs = [&](auto &&self, TreeNode *node) -> bool {
            if (node == nullptr)
                return false;
            bool lson = self(self, node->left);
            bool rson = self(self, node->right);
            if ((lson && rson) ||
                ((node->val == p->val || node->val == q->val) &&
                 (lson || rson))) {
                res = node;
            }
            return lson || rson || (node->val == p->val || node->val == q->val);
        };

        dfs(dfs, root);
        return res;
    }
};