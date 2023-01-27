struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode *temp = new ListNode(0, head);
        ListNode *last = head;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            if (last->val <= curr->val) {
                last = last->next;
            } else {
                ListNode *prev = temp;
                while (prev->next->val <= curr->val) {
                    prev = prev->next;
                }
                last->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = last->next;
        }

        return temp->next;
    }
};