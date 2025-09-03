struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr)
            return nullptr;

        auto temp = new ListNode(0, head);
        auto prev = temp;
        auto curr = head;
        auto next = head->next;

        while (next != nullptr) {
            if (curr->val == val) {
                prev->next = next;
                curr = next;
                next = curr->next;
            } else {
                prev = curr;
                curr = next;
                next = curr->next;
            }
        }

        if (curr->val == val)
            prev->next = nullptr;

        return temp->next;
    }
};