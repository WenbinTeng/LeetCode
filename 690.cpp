#include <queue>
#include <unordered_map>
#include <vector>

class Employee {
  public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution {
  public:
    int getImportance(std::vector<Employee *> employees, int id) {
        int res = 0;
        std::unordered_map<int, Employee *> um;
        std::queue<int> q;

        for (const auto &employee : employees) {
            um.insert({employee->id, employee});
        }

        q.push(id);

        while (!q.empty()) {
            int currId = q.front();

            for (const auto &subordinate : um[currId]->subordinates) {
                q.push(subordinate);
            }
            q.pop();

            res += um[currId]->importance;
        }

        return res;
    }
};