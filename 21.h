struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = new ListNode();
        ListNode* ph = p3;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                p3->next = new ListNode(p1->val);
                p3 = p3->next;
                p1 = p1->next;
            }
            else
            {
                p3->next = new ListNode(p2->val);
                p3 = p3->next;
                p2 = p2->next;
            }
        }
        while (p1)
        {
            p3->next = new ListNode(p1->val);
            p3 = p3->next;
            p1 = p1->next;
        }
        while (p2)
        {
            p3->next = new ListNode(p2->val);
            p3 = p3->next;
            p2 = p2->next;
        }

        p3 = ph->next;
        delete ph;
        return p3;
    }
};