#include <queue>
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
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};

        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto n = q.size();
            std::vector<int> layer;
            for (int i = 0; i < n; i++) {
                layer.push_back(q.front()->val);
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(layer);
        }

        return res;
    }
};