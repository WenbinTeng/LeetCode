#include <utility>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 1)
            return head;

        auto vhead = new ListNode(0, head);
        auto p = vhead;

        auto reverseK = [&](ListNode *node) -> ListNode * {
            auto kth = node->next;
            for (int i = 0; i < k; i++) {
                if (kth == nullptr)
                    return nullptr;
                else
                    kth = kth->next;
            }
            auto p1 = node->next;
            auto p2 = node->next->next;
            for (int i = 0; i < k - 1; i++) {
                auto t = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = t;
            }
            kth = node->next;
            node->next->next = p2;
            node->next = p1;
            return kth;
        };

        while (p != nullptr) {
            p = reverseK(p);
        }

        p = vhead;
        vhead = vhead->next;
        delete p;
        return vhead;
    }
};