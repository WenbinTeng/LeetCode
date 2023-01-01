#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        std::vector<int> res = {INT_MAX, INT_MIN};
        int flagIndex = -1;
        int prevIndex = -1;
        int currIndex = -1;

        ListNode *prev = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *next = head->next;

        int index = 0;

        while (next != nullptr) {
            prev = curr;
            curr = next;
            next = next->next;

            if (next != nullptr) {
                if (curr->val < prev->val && curr->val < next->val || curr->val > prev->val && curr->val > next->val) {
                    prevIndex = currIndex;
                    currIndex = index;
                    if (flagIndex == -1)
                        flagIndex = index;
                    if (prevIndex != -1)
                        res[0] = std::min(res[0], currIndex - prevIndex);
                }
            }

            ++index;
        }

        if (currIndex != flagIndex)
            res[1] = currIndex - flagIndex;

        if (res[0] == INT_MAX)
            res[0] = -1;
        if (res[1] == INT_MIN)
            res[1] = -1;

        return res;
    }
};