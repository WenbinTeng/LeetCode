struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        ListNode *prev = new ListNode(0, head);
        ListNode *curr = head;

        for (int count = 1; curr; ++count) {
            if (count % 2 == 0) {
                ListNode *lp = curr;
                ListNode *rp = curr;
                int i;

                for (i = 0; i < count - 1 && rp->next; ++i)
                    rp = rp->next;

                if (i % 2 != 0) {
                    curr = rp->next;
                    rp->next = nullptr;
                    prev->next = nullptr;

                    reverseLinkedList(lp);

                    prev->next = rp;
                    lp->next = curr;
                    prev = lp;
                }
            } else {
                ListNode *prevTemp = prev;
                ListNode *currTemp = curr;
                int i;

                for (i = 1; i <= count && curr; ++i) {
                    prev = curr;
                    curr = curr->next;

                    if (curr == nullptr) {
                        if (i % 2 == 0) {
                            ListNode *lp = currTemp;
                            ListNode *rp = currTemp;

                            for (int i = 0; rp->next; ++i)
                                rp = rp->next;

                            rp->next = nullptr;
                            prevTemp->next = nullptr;

                            reverseLinkedList(lp);

                            prevTemp->next = rp;
                            lp->next = nullptr;
                        }

                        break;
                    }
                }
            }
        }

        return head;
    }

  private:
    void reverseLinkedList(ListNode *head) {
        if (head == nullptr)
            return;

        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};