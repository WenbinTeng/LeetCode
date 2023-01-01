#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int maximumGood(std::vector<std::vector<int>> &statements) {
        int res = 0;

        for (int i = (1 << statements.size()) - 1; i >= 0; --i) {
            std::vector<bool> good(statements.size(), false);

            for (int j = 0, k = i; j < statements.size() && k; ++j) {
                good[j] = k % 2;
                k /= 2;
            }

            bool flag = true;

            for (int u = 0; u < statements.size(); ++u) {
                if (good[u]) {
                    for (int v = 0; v < statements.size(); ++v) {
                        if (statements[u][v] == 0 && good[v] || statements[u][v] == 1 && !good[v]) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        break;
                    }
                }
            }

            if (flag) {
                int count = 0;

                for (int j = 0; j < statements.size(); ++j) {
                    if (good[j])
                        ++count;
                }

                res = std::max(res, count);
            }
        }

        return res;
    }
};