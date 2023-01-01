#include <algorithm>
#include <queue>
#include <vector>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr)
            return {};

        std::vector<std::vector<int>> res;
        std::queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            res.push_back({});

            for (int i = q.size(); i > 0; --i) {
                if (q.front() != nullptr) {
                    res.back().push_back(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }

            if (res.back().empty())
                res.pop_back();
        }

        for (int i = 0; i < res.size(); ++i) {
            if (i % 2 == 1)
                std::reverse(res[i].begin(), res[i].end());
        }

        return res;
    }
};