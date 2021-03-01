#include <vector>

class Solution {
public:
    int minTrioDegree(int n, std::vector<std::vector<int>>& edges) {
        int res = __INT_MAX__;
        std::vector<int> indegree(n + 1, 0);
        std::vector<std::vector<int>> adjacent(n + 1, std::vector(n + 1, 0));
        for (const auto& iter : edges)
        {
            ++indegree[iter[0]];
            ++indegree[iter[1]];
            adjacent[iter[0]][iter[1]] = 1;
            adjacent[iter[1]][iter[0]] = 1;
        }

        for (int i = 0; i < n + 1; ++i)
        {
            if (res == 0) break;

            for (int j = i + 1; j < n + 1; ++j)
            {
                for (int k = j + 1; k < n + 1; ++k)
                {
                    if (adjacent[i][j] && adjacent[i][k] && adjacent[j][k])
                    {
                        res = std::min(res, indegree[i] + indegree[j] + indegree[k] - 6);
                    }
                }
            }
        }

        return res == __INT_MAX__ ? -1 : res;
    }
};