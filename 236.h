#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travel(root, p->val, q->val);
        return res;
    }

private:
    TreeNode* res;

    bool travel(TreeNode* node, int i, int j)
    {
        if (node == nullptr) return false;

        bool exist = node->val == i || node->val == j;

        bool leftExist  = travel(node->left,  i, j);
        bool rightExist = travel(node->right, i, j);

        if (leftExist && rightExist || leftExist && exist || rightExist && exist) res = node;

        return exist || leftExist || rightExist;
    }
};