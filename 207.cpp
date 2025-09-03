#include <queue>
#include <vector>

class Solution {
  public:
    bool canFinish(int numCourses,
                   std::vector<std::vector<int>> &prerequisites) {
        std::vector<std::vector<int>> edges(numCourses);
        std::vector<int> indeg(numCourses, 0);
        std::queue<int> q;
        int cnt = 0;

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
            ++cnt;

            for (const auto &iter : edges[q.front()]) {
                if (--indeg[iter] == 0) {
                    q.push(iter);
                }
            }

            q.pop();
        }

        return cnt == numCourses;
    }
};