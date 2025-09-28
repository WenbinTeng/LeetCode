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
    bool isValidBST(TreeNode* root) {
        bool res = true;
        auto postorder = [&](auto&& self, TreeNode* node) -> std::vector<int> {
            if (node->left == nullptr && node->right == nullptr)
                return {node->val, node->val};
            std::vector<int> v = {node->val, node->val};
            if (node->left != nullptr) {
                auto lv = self(self, node->left);
                int lmin = lv[0];
                int lmax = lv[1];
                res = res & lmax < node->val;
                v[0] = lmin;
            }
            if (node->right != nullptr) {
                auto rv = self(self, node->right);
                int rmin = rv[0];
                int rmax = rv[1];
                res = res & rmin > node->val;
                v[1] = rmax;
            }
            return v;
        };
        postorder(postorder, root);
        return res;
    }
};