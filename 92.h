struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *listPtr = new ListNode(0, head);
        ListNode *headPtr = listPtr;
        ListNode *tailPtr = listPtr;
        ListNode *prevPtr;
        ListNode *currPtr;
        ListNode *nextPtr;

        for (int i = 0; i < m - 1; i++)
            headPtr = headPtr->next;
        for (int i = 0; i < n + 1; i++)
            tailPtr = tailPtr->next;

        prevPtr = headPtr == nullptr ? nullptr : headPtr->next;
        currPtr = prevPtr == nullptr ? nullptr : prevPtr->next;
        nextPtr = currPtr == nullptr ? nullptr : currPtr->next;

        while (currPtr != tailPtr) {
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
            nextPtr = nextPtr == nullptr ? nullptr : nextPtr->next;
        }

        headPtr->next->next = tailPtr;
        headPtr->next = prevPtr;

        headPtr = listPtr->next;
        delete listPtr;
        return headPtr;
    }
};