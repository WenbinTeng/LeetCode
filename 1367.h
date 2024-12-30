struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr)
            return false;

        bool res = false;

        if (head->val == root->val)
            res = comparePath(head, root);
        if (!res)
            res = isSubPath(head, root->left);
        if (!res)
            res = isSubPath(head, root->right);

        return res;
    }

private:
    bool comparePath(ListNode* head, TreeNode* root) {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;

        bool res = false;

        if (head->val == root->val) {
            res = comparePath(head->next, root->left);
            if (!res)
                res = comparePath(head->next, root->right);
        }
        
        return res;
    }
};