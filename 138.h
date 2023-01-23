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
    std::unordered_map<Node *, Node *> um;

    Node *copyRandomList(Node *head) {
        if (head == nullptr)
            return nullptr;
        if (!um.count(head)) {
            Node *headNew = new Node(head->val);
            um[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return um[head];
    }
};