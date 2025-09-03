#include <unordered_map>
#include <vector>

class Solution {
  public:
    int findCenter(std::vector<std::vector<int>> &edges) {
        std::unordered_map<int, int> um;

        for (const auto &edge : edges) {
            if (++um[edge[0]] > 1)
                return edge[0];
            if (++um[edge[1]] > 1)
                return edge[1];
        }

        return edges[0][0];
    }
};