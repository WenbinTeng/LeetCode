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

        ListNode *prevPtr = head;
        ListNode *nextPtr = head->next;
        ListNode *tempPtr = head->next;
        while (nextPtr != nullptr) {
            if (prevPtr->val == nextPtr->val) {
                tempPtr = nextPtr;
                nextPtr = nextPtr->next;
                prevPtr->next = nextPtr;
                delete tempPtr;
                tempPtr = nullptr;
            } else {
                prevPtr = nextPtr;
                nextPtr = nextPtr->next;
            }
        }

        return head;
    }
};