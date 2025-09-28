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
    std::vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr)
            return {};

        std::vector<int> res;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; i++) {
                if (i == size - 1) {
                    res.push_back(q.front()->val);
                }
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();
            }
        }

        return res;
    }
};