#include <algorithm>
#include <vector>

class Solution {
  public:
    long long maxSubarrays(int n,
                           std::vector<std::vector<int>> &conflictingPairs) {
        long long res = 0;
        std::vector<long long> extra(n + 2);
        std::vector<int> b = {n + 1, n + 1};
        std::vector<std::vector<int>> groups(n + 1);

        for (auto &p : conflictingPairs) {
            int a = p[0];
            int b = p[1];
            if (a > b) {
                std::swap(a, b);
            }
            groups[a].push_back(b);
        }

        for (int a = n; a > 0; a--) {
            auto &list_b = groups[a];
            b.insert(b.end(), list_b.begin(), list_b.end());
            std::sort(b.begin(), b.end());
            b.resize(2);
            res += b[0] - a;
            extra[b[0]] += b[1] - b[0];
        }

        return res + *std::max_element(extra.begin(), extra.end());
    }
};