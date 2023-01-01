struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *newList = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *p3 = newList;
        int carry = 0;

        while (p1 && p2) {
            int val = p1->val + p2->val + carry;
            carry = val / 10;
            val = val % 10;
            p3->next = new ListNode(val);
            p3 = p3->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            int val = p1->val + carry;
            carry = val / 10;
            val = val % 10;
            p3->next = new ListNode(val);
            p3 = p3->next;
            p1 = p1->next;
        }
        while (p2) {
            int val = p2->val + carry;
            carry = val / 10;
            val = val % 10;
            p3->next = new ListNode(val);
            p3 = p3->next;
            p2 = p2->next;
        }
        if (carry) {
            p3->next = new ListNode(1);
        }

        return newList->next;
    }
};