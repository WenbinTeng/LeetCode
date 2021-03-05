#include <vector>
#include <queue>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> um;
        um.insert(std::make_pair(node, new Node(node->val)));

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            auto n = q.front();

            for (const auto& neighbor : n->neighbors)
            {
                if (um.find(neighbor) == um.end())
                {
                    um.insert(std::make_pair(neighbor, new Node(neighbor->val)));
                    q.push(neighbor);
                }

                um[n]->neighbors.push_back(um[neighbor]);
            }

            q.pop();
        }

        return um[node];
    }
};