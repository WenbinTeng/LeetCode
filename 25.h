#include <utility>

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        ListNode* list = new ListNode(0, head);
        ListNode* prev = list;
        ListNode* curr = head;
        ListNode* next = head;

        while (curr)
        {
            for (int i = 0; i < k; i++)
            {
                if (!next) return list->next; next = next->next;
            }

            std::pair<ListNode*, ListNode*> ret = reverseKNode(curr, k);
            prev->next = ret.first;
            prev = ret.second;
            prev->next = next;
            curr = next;
        }

        return list->next;
    }

private:
    std::pair<ListNode*, ListNode*> reverseKNode(ListNode* head, int k)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        for (int i = 0; i < k; i++)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr ? curr->next : nullptr;
        }

        return std::make_pair(prev, head);
    }

};