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
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
        return inorder.empty() || postorder.empty() ? nullptr : buildNode(inorder, postorder, 0, inorder.size() - 1);
    }

private:
    int index = 0;

    TreeNode *buildNode(std::vector<int> &inorder, std::vector<int> &postorder, int inBegin, int inEnd) {
        if (index == postorder.size())
            return nullptr;

        for (int i = inBegin; i <= inEnd; ++i) {
            if (postorder[postorder.size() - 1 - index] == inorder[i]) {
                TreeNode *node = new TreeNode(postorder[postorder.size() - 1 - index++]);
                node->right = buildNode(inorder, postorder, i + 1, inEnd);
                node->left = buildNode(inorder, postorder, inBegin, i - 1);
                return node;
            }
        }

        return nullptr;
    }
};