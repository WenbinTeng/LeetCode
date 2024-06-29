struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;

        int len = 0;
        ListNode *prevPtr = head;
        ListNode *nextPtr = head;

        for (ListNode *i = head; i != nullptr; i = i->next)
            ++len;

        k = k % len;

        for (int i = 0; i < k; i++) {
            nextPtr = nextPtr->next;
        }

        while (nextPtr->next != nullptr) {
            prevPtr = prevPtr->next;
            nextPtr = nextPtr->next;
        }

        nextPtr->next = head;
        head = prevPtr->next;
        prevPtr->next = nullptr;

        return head;
    }
};