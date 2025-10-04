struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        auto pa = headA;
        auto pb = headB;

        while (pa != pb) {
            pa = (pa == nullptr) ? headB : pa->next;
            pb = (pb == nullptr) ? headA : pb->next;
        }

        return pa;
    }
};