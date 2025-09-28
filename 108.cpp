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
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        auto recursiveBuild = [&](auto &&self, int l, int r) -> TreeNode * {
            if (l > r)
                return nullptr;
            int mid = (l + r) / 2;
            auto lt = self(self, l, mid - 1);
            auto rt = self(self, mid + 1, r);
            auto root = new TreeNode(nums[mid], lt, rt);
            return root;
        };
        return recursiveBuild(recursiveBuild, 0, nums.size() - 1);
    }
};