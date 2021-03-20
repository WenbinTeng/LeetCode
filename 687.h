#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, root->val + 1);
        return res;
    }

private:
    int res = 0;

    int dfs(TreeNode* node, int rootVal)
    {
        if (node == nullptr) return 0;

        int leftDepth  = dfs(node->left,  node->val);
        int rightDepth = dfs(node->right, node->val);

        res = std::max(res, leftDepth + rightDepth);

        return node->val == rootVal ? std::max(leftDepth, rightDepth) + 1 : 0;
    }
};