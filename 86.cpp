struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr)
            return nullptr;

        ListNode *headPtr = new ListNode(0, head);
        ListNode *tailPtr = headPtr;
        ListNode *prevPtr;
        ListNode *nextptr;

        while (tailPtr->next != nullptr && tailPtr->next->val < x)
            tailPtr = tailPtr->next;

        nextptr = tailPtr->next;

        while (nextptr != nullptr) {
            if (nextptr->val < x) {
                prevPtr->next = nextptr->next;
                nextptr->next = tailPtr->next;
                tailPtr->next = nextptr;
                tailPtr = nextptr;
                nextptr = prevPtr->next;
            } else {
                prevPtr = nextptr;
                nextptr = nextptr->next;
            }
        }

        nextptr = headPtr->next;
        delete headPtr;
        return nextptr;
    }
};