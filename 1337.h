#include <vector>
#include <queue>
#include <numeric>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (int i = 0; i < m; i++) {
            pq.push({std::accumulate(mat[i].begin(), mat[i].end(), 0), i});
        }

        for (int i = 0; i < k; i++) {
            auto [_, index] = pq.top();
            pq.pop();
            res.push_back(index);
        }

        return res;
    }
};