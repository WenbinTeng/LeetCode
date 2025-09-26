struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        auto p1 = list1;
        auto p2 = list2;
        auto vhead = new ListNode();
        auto curr = vhead;

        while (p1 != nullptr || p2 != nullptr) {
            if (p1 != nullptr && p2 != nullptr) {
                if (p1->val < p2->val) {
                    curr->next = p1;
                    curr = p1;
                    p1 = p1->next;
                } else {
                    curr->next = p2;
                    curr = p2;
                    p2 = p2->next;
                }
            } else if (p1 != nullptr) {
                curr->next = p1;
                curr = p1;
                p1 = p1->next;
            } else if (p2 != nullptr) {
                curr->next = p2;
                curr = p2;
                p2 = p2->next;
            }
        }

        curr = vhead;
        vhead = vhead->next;
        delete curr;

        return vhead;
    }
};