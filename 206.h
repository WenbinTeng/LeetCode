struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        auto prev = head;
        auto curr = prev->next;
        auto next = curr->next;
        
        head->next = nullptr;
        while (curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr == nullptr ? nullptr : curr->next;
        }

        return prev;
    }
};