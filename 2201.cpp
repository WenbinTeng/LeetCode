#include <unordered_set>
#include <vector>

class Solution {
  public:
    int digArtifacts(int n, std::vector<std::vector<int>> &artifacts,
                     std::vector<std::vector<int>> &dig) {
        int res = 0;
        std::unordered_set<long long> us;

        for (const auto d : dig) {
            us.insert(((long long)d[0] << 32) | d[1]);
        }

        for (const auto artifact : artifacts) {
            bool isDiged = true;
            int r1 = artifact[0];
            int c1 = artifact[1];
            int r2 = artifact[2];
            int c2 = artifact[3];

            for (int i = r1; i <= r2 & isDiged; ++i) {
                for (int j = c1; j <= c2 & isDiged; ++j) {
                    if (!us.count(((long long)i << 32) | j)) {
                        isDiged = false;
                    }
                }
            }

            if (isDiged)
                ++res;
        }

        return res;
    }
};