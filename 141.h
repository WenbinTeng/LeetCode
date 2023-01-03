struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;

        auto slowPtr = head;
        auto fastPtr = head->next;

        while (fastPtr != nullptr) {
            if (slowPtr == fastPtr) {
                return true;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
            if (fastPtr != nullptr)
                fastPtr = fastPtr->next;
        }

        return false;
    }
};