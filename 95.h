#include <vector>

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
    std::vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

private:
    std::vector<TreeNode*> dfs(int begin, int end)
    {
        if (begin > end) return {nullptr};

        std::vector<TreeNode*> res;

        for (int i = begin; i <= end; i++)
        {
            std::vector<TreeNode*> leftTrees  = dfs(begin, i - 1);
            std::vector<TreeNode*> rightTrees = dfs(i + 1,   end);

            for (auto& left : leftTrees)
            {
                for (auto& right : rightTrees)
                {
                    res.push_back(new TreeNode(i, left, right));
                }
            }
        }

        return res;
    }
};