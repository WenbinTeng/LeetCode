#include <unordered_map>

class Node {
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        auto res = new Node(0);
        auto newPtr = res;
        auto oldPtr = head;
        std::unordered_map<Node *, Node *> dict;

        while (oldPtr != nullptr) {
            if (dict.count(oldPtr)) {
                newPtr->next = dict[oldPtr];
            } else {
                newPtr->next = new Node(oldPtr->val);
                dict[oldPtr] = newPtr->next;
            }
            if (oldPtr->random != nullptr) {
                if (dict.count(oldPtr->random)) {
                    newPtr->next->random = dict[oldPtr->random];
                } else {
                    newPtr->next->random = new Node(oldPtr->random->val);
                    dict[oldPtr->random] = newPtr->next->random;
                }
            }
            oldPtr = oldPtr->next;
            newPtr = newPtr->next;
        }

        auto t = res;
        res = res->next;
        delete t;
        return res;
    }
};