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
    int pathSum(TreeNode *root, int targetSum) {
        std::unordered_map<long long, int> prevSum;
        prevSum[0] = 1;

        auto dfs = [&](auto &&self, TreeNode *node, long long currSum) -> int {
            if (node == nullptr)
                return 0;

            int cnt = 0;
            currSum += node->val;
            if (prevSum.count(currSum - targetSum)) {
                cnt += prevSum[currSum - targetSum];
            }

            prevSum[currSum]++;
            cnt += self(self, node->left, currSum);
            cnt += self(self, node->right, currSum);
            prevSum[currSum]--;

            return cnt;
        };

        return dfs(dfs, root, 0);
    }
};