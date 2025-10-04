#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        auto slowPtr = head;
        auto fastPtr = head;

        while (fastPtr != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            if (fastPtr)
                fastPtr = fastPtr->next;
            else
                return nullptr;
            if (fastPtr == slowPtr) {
                auto ptr = head;
                while (ptr != slowPtr) {
                    ptr = ptr->next;
                    slowPtr = slowPtr->next;
                }
                return ptr;
            }
        }

        return nullptr;
    }
};