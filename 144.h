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
    std::vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }

private:
    std::vector<int> res;

    void preorder(TreeNode* node)
    {
        if (node == nullptr) return;

        res.push_back(node->val);
        preorder(node->left );
        preorder(node->right);
    }
};