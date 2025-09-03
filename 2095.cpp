struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *prev = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *fast = head;

        while (fast->next != nullptr) {
            prev = prev->next;
            curr = curr->next;
            fast = fast->next;
            fast = fast->next;

            if (fast == nullptr)
                break;
        }

        prev->next = curr->next;

        return head;
    }
};