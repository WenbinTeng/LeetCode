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
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        const int n = preorder.size();
        std::unordered_map<int, int> dict;

        for (int i = 0; i < n; i++) {
            dict[inorder[i]] = i;
        }

        auto build = [&](auto &&self, int root, int inleft,
                         int inright) -> TreeNode * {
            if (inleft > inright)
                return nullptr;
            int index = dict[preorder[root]];
            auto lt = self(self, root + 1, inleft, index - 1);
            auto rt =
                self(self, root + (index - inleft + 1), index + 1, inright);
            return new TreeNode(preorder[root], lt, rt);
        };

        return build(build, 0, 0, n - 1);
    }
};