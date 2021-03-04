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
    std::vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }

private:
    std::vector<int> res;

    void postorder(TreeNode* node)
    {
        if (node == nullptr) return;

        postorder(node->left );
        postorder(node->right);
        res.push_back(node->val);
    }
};