#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        auto ptr = head;
        std::unordered_set<ListNode*> us;

        while (ptr != nullptr) {
            if (us.count(ptr)) {
                return ptr;
            }
            us.insert(ptr);
            ptr = ptr->next;
        }

        return nullptr;
    }
};