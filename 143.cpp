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
    void reorderList(ListNode *head) {
        if (head == nullptr)
            return;

        auto node = head;
        std::vector<ListNode *> mem;

        while (node != nullptr) {
            mem.push_back(node);
            node = node->next;
        }

        for (int i = 0, j = mem.size() - 1; i < j;) {
            mem[i++]->next = mem[j];
            if (i == j) {
                mem[i]->next = nullptr;
                break;
            }
            mem[j--]->next = mem[i];
            if (i == j) {
                mem[i]->next = nullptr;
                break;
            }
        }
    }
};