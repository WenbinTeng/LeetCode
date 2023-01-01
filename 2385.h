#include <unordered_map>
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
    int amountOfTime(TreeNode *root, int start) {
        preorder(root, start);
        getMaxLen(startPtr, 0, -1, false);
        father[root->val] = nullptr;
        return res;
    }

private:
    int res = 0;
    TreeNode *startPtr;
    std::unordered_map<int, TreeNode *> father;

    void preorder(TreeNode *node, int start) {
        if (node == nullptr)
            return;

        if (node->val == start)
            startPtr = node;

        if (node->left != nullptr) {
            father[node->left->val] = node;
            preorder(node->left, start);
        }
        if (node->right != nullptr) {
            father[node->right->val] = node;
            preorder(node->right, start);
        }
    }

    void getMaxLen(TreeNode *node, int cnt, int prev, bool isChild) {
        if (node == nullptr)
            return;

        res = std::max(res, cnt);

        if (isChild) {
            getMaxLen(node->left, cnt + 1, node->val, true);
            getMaxLen(node->right, cnt + 1, node->val, true);
        } else {
            if (node->left != nullptr && node->left->val != prev) {
                getMaxLen(node->left, cnt + 1, node->val, true);
            }
            if (node->right != nullptr && node->right->val != prev) {
                getMaxLen(node->right, cnt + 1, node->val, true);
            }
            if (father[node->val] != nullptr) {
                getMaxLen(father[node->val], cnt + 1, node->val, false);
            }
        }
    }
};