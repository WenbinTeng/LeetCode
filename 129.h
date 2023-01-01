#include <string>

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
    int sumNumbers(TreeNode *root) {
        return root == nullptr ? 0 : searchPath(root, "");
    }

private:
    int searchPath(TreeNode *node, std::string path) {
        return node == nullptr ? 0 : node->left == nullptr && node->right == nullptr ? std::stoi(path + (char)(node->val + '0'))
                                                                                     : searchPath(node->left, path + (char)(node->val + '0')) + searchPath(node->right, path + (char)(node->val + '0'));
    }
};