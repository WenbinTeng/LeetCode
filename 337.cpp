#include <unordered_map>
#include <vector>

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
    int rob(TreeNode *root) {
        dfs(root);
        return std::max(f[root], g[root]);
    }

  private:
    std::unordered_map<TreeNode *, int> f, g;

    void dfs(TreeNode *node) {
        if (node == nullptr)
            return;
        dfs(node->left);
        dfs(node->right);

        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = std::max(f[node->left], g[node->left]) +
                  std::max(f[node->right], g[node->right]);
    }
};