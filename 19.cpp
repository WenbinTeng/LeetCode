struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto vhead = new ListNode(0, head);
        auto p1 = vhead;
        auto p2 = vhead;

        for (int i = 0; i < n; i++) {
            p2 = p2->next;
        }

        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        auto next = p1->next;
        p1->next = p1->next->next;
        if (next != nullptr)
            delete next;

        next = vhead;
        vhead = vhead->next;
        delete next;
        return vhead;
    }
};