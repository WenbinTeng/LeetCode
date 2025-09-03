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
        ListNode *ph = new ListNode(0, head);
        ListNode *p1 = ph;
        ListNode *p2 = ph;

        for (int i = 0; i <= n; i++)
            p2 = p2->next;
        while (p2) {
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 == ph) {
            return head->next;
        } else {
            ListNode *temp = p1->next;
            p1->next = p1->next->next;
            delete temp;
            return head;
        }
    }
};