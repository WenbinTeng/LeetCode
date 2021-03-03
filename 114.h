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
    void flatten(TreeNode* root) {
        std::vector<TreeNode*> rec;

        preorder(root, rec);

        for (int i = 1; i < rec.size(); ++i)
        {
            rec[i - 1]->left  = nullptr;
            rec[i - 1]->right = rec[i];
        }
    }

private:
    void preorder(TreeNode* node, std::vector<TreeNode*>& rec)
    {
        if (node != nullptr)
        {
            rec.push_back(node);
            preorder(node->left,  rec);
            preorder(node->right, rec);
        }
    }
};