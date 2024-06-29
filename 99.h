#include <vector>

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
    void recoverTree(TreeNode *root) {
        std::vector<int> rec;

        inorder(root, rec);

        int swapValX = -1;
        int swapValY = -1;

        for (int i = 1; i < rec.size(); i++) {
            if (rec[i - 1] > rec[i]) {
                swapValX = swapValX == -1 ? rec[i - 1] : swapValX;
                swapValY = rec[i];
            }
        }

        recover(root, swapValX, swapValY);

        std::swap(swapNodeX->val, swapNodeY->val);
    }

private:
    TreeNode *swapNodeX;
    TreeNode *swapNodeY;

    void inorder(TreeNode *node, std::vector<int> &rec) {
        if (node == nullptr)
            return;

        inorder(node->left, rec);
        rec.push_back(node->val);
        inorder(node->right, rec);
    }

    void recover(TreeNode *node, int x, int y) {
        if (node == nullptr)
            return;

        if (node->val == x)
            swapNodeX = node;
        if (node->val == y)
            swapNodeY = node;

        recover(node->left, x, y);
        recover(node->right, x, y);
    }
};