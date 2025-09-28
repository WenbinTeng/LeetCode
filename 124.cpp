#include <algorithm>

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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        
        auto dfs = [&](auto&& self, TreeNode* node) -> int {
            if (node == nullptr)
                return 0;
            int lsum = std::max(0, self(self, node->left));
            int rsum = std::max(0, self(self, node->right));
            int path = lsum + rsum + node->val;
            res = std::max(res, path);
            return node->val + std::max(lsum, rsum);
        };

        dfs(dfs, root);

        return res;
    }
};