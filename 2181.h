struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *resHead = new ListNode;
        ListNode *resTail = resHead;
        ListNode *prevZero = head;
        ListNode *nextZero = head->next;

        while (true) {
            if (nextZero == nullptr)
                break;

            int sum = 0;

            while (nextZero->val != 0) {
                sum += nextZero->val;
                nextZero = nextZero->next;
            }

            resTail->next = new ListNode(sum);
            resTail = resTail->next;

            prevZero = nextZero;
            nextZero = nextZero->next;
        }

        return resHead->next;
    }
};