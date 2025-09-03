struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode *list = new ListNode(0, head);
        ListNode *prev = list;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr) {
            if (next == nullptr)
                break;
            else {
                prev->next = next;
                curr->next = next->next;
                next->next = curr;

                prev = curr;
                curr = curr->next;
                next = curr ? curr->next : nullptr;
            }
        }

        curr = list->next;
        delete list;
        return curr;
    }
};