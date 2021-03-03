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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr ? true : symmetricCheck(root->left, root->right);
    }

private:
    bool symmetricCheck(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr) return false;
        else if (q == nullptr) return false;
        else if (p->val != q->val) return false;

        return symmetricCheck(p->left, q->right) && symmetricCheck(p->right, q->left);
    }
};