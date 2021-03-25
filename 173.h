#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        pushNext(root);
    }
    
    int next() {
        auto node = s.top();
        s.pop();
        pushNext(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

private:
    std::stack<TreeNode*> s;

    void pushNext(TreeNode* node)
    {
        for (auto iter = node; iter != nullptr; iter = iter->left) s.push(iter);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */