#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr)
            return true;

        auto half = getHalfListNode(head);
        auto rest = reverseList(half->next);

        auto p1 = head;
        auto p2 = rest;

        while (p2 != nullptr) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }

private:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        auto prev = head;
        auto curr = prev->next;
        auto next = curr->next;

        head->next = nullptr;
        while (curr != nullptr) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr == nullptr ? nullptr : curr->next;
        }

        return prev;
    }

    ListNode *getHalfListNode(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};