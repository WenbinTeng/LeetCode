#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        preorder1(root1);
        return preorder2(root2) && rec.empty();
    }

private:
    std::queue<int> rec;

    void preorder1(TreeNode *node1) {
        if (node1 == nullptr)
            return;

        preorder1(node1->left);
        if (node1->left == nullptr && node1->right == nullptr)
            rec.push(node1->val);
        preorder1(node1->right);
    }

    bool preorder2(TreeNode *node2) {
        if (node2 == nullptr)
            return true;

        if (!preorder2(node2->left))
            return false;
        if (node2->left == nullptr && node2->right == nullptr) {
            if (!rec.empty() && node2->val == rec.front())
                rec.pop();
            else
                return false;
        }
        if (!preorder2(node2->right))
            return false;

        return true;
    }
};