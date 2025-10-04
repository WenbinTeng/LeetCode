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
        if (head == nullptr)
            return nullptr;

        auto currPtr = new ListNode(0, head);
        auto nextPtr = head;

        while (nextPtr != nullptr) {
            auto t = nextPtr->next;
            nextPtr->next = currPtr;
            currPtr = nextPtr;
            nextPtr = t;
        }

        delete head->next;
        head->next = nullptr;
        return currPtr;
    }
};