#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            for (int i = q.size(); i > 0; --i)
            {
                Node* temp = q.front();
                q.pop();

                if (temp != nullptr)
                {
                    while (!q.empty() && q.front() == nullptr && i > 0) {q.pop(); --i;}

                    temp->next = i <= 1 ? nullptr : q.front();
                    q.push(temp->left );
                    q.push(temp->right);
                }
            }
        }

        return root;
    }
};