#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> findOrder(int numCourses,
                               std::vector<std::vector<int>> &prerequisites) {
        if (numCourses == 0)
            return {};

        std::vector<int> res;
        std::vector<std::vector<int>> edges(numCourses);
        std::vector<int> indeg(numCourses, 0);
        std::queue<int> q;

        for (const auto &info : prerequisites) {
            edges[info[1]].push_back(info[0]);
            indeg[info[0]] += 1;
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            res.push_back(q.front());

            for (const auto &iter : edges[q.front()]) {
                if (--indeg[iter] == 0) {
                    q.push(iter);
                }
            }

            q.pop();
        }

        return res.size() == numCourses ? res : std::vector<int>();
    }
};