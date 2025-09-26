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
        auto p1 = l1;
        auto p2 = l2;
        auto vhead = new ListNode();
        auto curr = vhead;
        int carry = 0;

        while (p1 != nullptr || p2 != nullptr || carry != 0) {
            int val = carry;
            if (p1 != nullptr) {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                val += p2->val;
                p2 = p2->next;
            }
            curr->next = new ListNode(val % 10);
            curr = curr->next;
            carry = val / 10;
        }

        curr = vhead;
        vhead = vhead->next;
        delete curr;

        return vhead;
    }
};