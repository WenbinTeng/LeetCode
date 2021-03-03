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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return preorder.empty() || inorder.empty() ? nullptr : buildNode(preorder, inorder, 0, inorder.size() - 1);
    }

private:
    int index = 0;

    TreeNode* buildNode(std::vector<int>& preorder, std::vector<int>& inorder, int inBegin, int inEnd)
    {
        if (index == preorder.size()) return nullptr;

        for (int i = inBegin; i <= inEnd; ++i)
        {
            if (preorder[index] == inorder[i])
            {
                return new TreeNode(preorder[index++], buildNode(preorder, inorder, inBegin, i - 1), buildNode(preorder, inorder, i + 1, inEnd));
            }
        }

        return nullptr;
    }
};