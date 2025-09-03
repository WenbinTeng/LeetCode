struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        ListNode *headPtr = new ListNode(0, head);
        ListNode *prevPtr = headPtr;
        ListNode *currPtr = head->next;
        ListNode *nextPtr = head->next;
        while (nextPtr != nullptr) {
            currPtr = prevPtr->next;
            nextPtr = currPtr->next;
            if (currPtr->val == nextPtr->val) {
                while (nextPtr != nullptr && currPtr->val == nextPtr->val) {
                    nextPtr = nextPtr->next;
                }

                prevPtr->next = nextPtr;

                while (currPtr != nullptr && currPtr != nextPtr) {
                    ListNode *tempPtr;
                    tempPtr = currPtr->next;
                    delete currPtr;
                    currPtr = tempPtr;
                }

                nextPtr = nextPtr == nullptr ? nullptr : nextPtr->next;
            } else {
                prevPtr = currPtr;
                currPtr = nextPtr;
                nextPtr = nextPtr->next;
            }
        }

        currPtr = headPtr->next;
        delete headPtr;
        return currPtr;
    }
};