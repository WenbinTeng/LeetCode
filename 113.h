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
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> path;

        dfs(root, res, path, 0, targetSum);

        return res;
    }

private:
    void dfs(TreeNode* node, std::vector<std::vector<int>>& res, std::vector<int>& path, int sum, int targetSum)
    {
        if (node == nullptr) return;
        
        if (node->left == nullptr && node->right == nullptr && sum + node->val == targetSum)
        {
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(node->val);
        dfs(node->left,  res, path, sum + node->val, targetSum);
        dfs(node->right, res, path, sum + node->val, targetSum);
        path.pop_back();
    }
};