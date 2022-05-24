#include <algorithm>

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
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }

private:
    int res = 0;

    std::pair<int, int> postorder(TreeNode* node)
    {
        if (node == nullptr) return {0, 0};

        auto [leftVal, leftNum] = postorder(node->left);
        auto [rightVal, rightNum] = postorder(node->right);

        int totalVal = leftVal + rightVal + node->val;
        int totalNum = leftNum + rightNum + 1;

        if (totalVal / totalNum == node->val)
        {
            ++res;
        }

        return {totalVal, totalNum};
    }
};