struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (original == nullptr)
            return nullptr;
        else if (original == target)
            return cloned;

        auto t = getTargetCopy(original->left, cloned->left, target);

        if (t != nullptr)
            return t;

        t = getTargetCopy(original->right, cloned->right, target);

        return t;
    }
};