#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int maxProduct(TreeNode *root) {
        const int mod = 1e+9 + 7;
        sum = calPrevSum(root);
        getMaxProduct(root);
        return maxP % mod;
    }

  private:
    int sum = 0;
    long long maxP = 0;

    int calPrevSum(TreeNode *root) {
        if (root == nullptr)
            return 0;
        root->val += calPrevSum(root->left);
        root->val += calPrevSum(root->right);
        return root->val;
    }

    void getMaxProduct(TreeNode *root) {
        if (root == nullptr)
            return;
        maxP = std::max(maxP, (long long)(sum - root->val) * root->val);
        getMaxProduct(root->left);
        getMaxProduct(root->right);
    }
};