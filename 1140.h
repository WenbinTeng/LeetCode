#include <vector>
#include <algorithm>

class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        lastSum = std::vector<int>(piles);
        visited = std::vector<std::vector<int>>(piles.size(), std::vector<int>(piles.size(), -1));

        
        for (int i = lastSum.size() - 2; i >= 0; --i) {
            lastSum[i] += lastSum[i + 1];
        }

        return dfs(0, 1);
    }

private:
    std::vector<int> lastSum;
    std::vector<std::vector<int>> visited;

    int dfs(int index, int M) {
        if (index + M * 2 >= lastSum.size())
            return lastSum[index];

        if (visited[index][M] != -1)
            return visited[index][M];

        int minTake = INT_MAX;

        for (int x = 1; x <= M * 2; ++x) {
            minTake = std::min(minTake, dfs(index + x, std::max(x, M)));
        }

        visited[index][M] = lastSum[index] - minTake;

        return visited[index][M];
    }
};