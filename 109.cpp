#include <vector>

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
    TreeNode *sortedListToBST(ListNode *head) {
        return head == nullptr ? nullptr : build(head, nullptr);
    }

  private:
    TreeNode *build(ListNode *head, ListNode *tail) {
        if (head == tail)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != tail) {
            if (fast != tail)
                fast = fast->next;
            else
                break;
            if (fast != tail)
                fast = fast->next;
            else
                break;
            slow = slow->next;
        }

        return new TreeNode(slow->val, build(head, slow),
                            build(slow->next, tail));
    }
};