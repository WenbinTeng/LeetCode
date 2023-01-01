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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return sameCheck(p, q);
    }

private:
    bool sameCheck(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr)
            return false;
        else if (q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;

        return sameCheck(p->left, q->left) && sameCheck(p->right, q->right);
    }
};