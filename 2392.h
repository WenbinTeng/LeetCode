#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
        std::vector<std::vector<int>> res(k, std::vector<int>(k));

        std::vector<int> rows = topoSort(k, rowConditions);
        std::vector<int> cols = topoSort(k, colConditions);

        if (rows[0] == -1 || cols[0] == -1) return {};

        for (int i = 1; i <= k; i++)
        {
            res[rows[i]][cols[i]] = i;
        }
        
        return res;
    }

private:
    std::vector<std::vector<int>> edges;
    std::vector<int> degrees;

    std::vector<int> topoSort(int n, std::vector<std::vector<int>> &condisions) {
        std::vector<int> ret(n + 1);
        std::queue<int> q;
        edges = std::vector<std::vector<int>>(n + 1, std::vector<int>());
        degrees = std::vector<int>(n + 1);

        for (auto &vec : condisions)
        {
            edges[vec[0]].push_back(vec[1]);
            ++degrees[vec[1]];
        }

        for (int i = 1; i <= n; i++)
        {
            if (degrees[i] == 0) q.push(i);
        }

        int curr = 0;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ret[front] = curr;
            curr++;
            for (int parent : edges[front])
            {
                degrees[parent]--;
                if (degrees[parent] == 0) q.push(parent);
            }
        }

        if (curr != n) ret[0] = -1;

        return ret;
    }
};