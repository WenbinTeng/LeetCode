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

        auto vhead = new ListNode(0, head);
        auto p = vhead;

        while (p != nullptr) {
            auto p1 = p->next;
            auto p2 = p1 ? p1->next : nullptr;

            if (p1 && p2) {
                auto t = p2->next;
                p->next = p2;
                p2->next = p1;
                p1->next = t;
                p = p1;
            } else {
                break;
            }
        }

        p = vhead;
        vhead = vhead->next;
        delete p;
        return vhead;
    }
};