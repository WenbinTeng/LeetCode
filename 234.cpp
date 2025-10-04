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
        frontNode = head;
        return recursiveCheck(head);
    }

  private:
    ListNode *frontNode;

    bool recursiveCheck(ListNode *currNode) {
        if (currNode != nullptr) {
            if (!recursiveCheck(currNode->next))
                return false;
            if (currNode->val != frontNode->val)
                return false;
            frontNode = frontNode->next;
        }
        return true;
    }
};