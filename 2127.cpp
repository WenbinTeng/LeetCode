#include <vector>

class Solution {
  public:
    int maximumInvitations(std::vector<int> &favorite) {
        cls = std::vector<int>(favorite.size());
        dep = std::vector<int>(favorite.size());
        rev = std::vector<std::vector<int>>(favorite.size());

        for (int i = 0; i < favorite.size(); ++i) {
            rev[favorite[i]].push_back(i);
        }

        for (int i = 0; i < favorite.size(); ++i) {
            if (!cls[i])
                loopDfs(i);
        }

        pairLen = 0;
        for (auto &[u, v] : pairs) {
            pairLen += pairDfs(u, v, 1);
            pairLen += pairDfs(v, u, 1);
        }

        return std::max(loopMax, pairLen);
    }

  private:
    std::vector<int> cls;
    std::vector<int> dep;
    std::vector<std::pair<int, int>> pairs;
    std::vector<std::vector<int>> rev;
    int loopMax;
    int pairLen;

    void loopDfs(int u) {
        cls[u] = 1;

        for (auto v : rev[u]) {
            if (!cls[v]) {
                dep[v] = dep[u] + 1;
                loopDfs(v);
            } else if (cls[v] == 1) {
                int loop = dep[u] - dep[v] + 1;
                loopMax = std::max(loopMax, loop);
                if (loop == 2)
                    pairs.push_back({u, v});
            } else {
            }
        }

        cls[u] = 2;
    }

    int pairDfs(int u, int v, int d) {
        int maxDepth = d;

        for (auto n : rev[u]) {
            if (n != v)
                maxDepth = std::max(maxDepth, pairDfs(n, v, d + 1));
        }

        return maxDepth;
    }
};