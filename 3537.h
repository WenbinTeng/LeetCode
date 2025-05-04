#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> specialGrid(int N) {
        if (N == 0)
            return {{0}};
        
        std::vector<std::vector<int>> init = {{3, 0}, {2, 1}};

        for (int i = 1; i < N; i++) {
            int bound = 1 << (i + 1);
            int half = bound / 2;
            int base = init.size() * init[0].size();
            std::vector<std::vector<int>> next(bound, std::vector<int>(bound));
            for (int i = 0; i < bound; i++) {
                for (int j = 0; j < bound; j++) {
                    int si = i % half;
                    int sj = j % half;
                    if        (i < half && j < half) {
                        next[i][j] = base * 3 + init[si][sj];
                    } else if (i >= half && j < half) {
                        next[i][j] = base * 2 + init[si][sj];
                    } else if (i <  half && j >= half) {
                        next[i][j] = init[si][sj];
                    } else if (i >= half && j >= half) {
                        next[i][j] = base + init[si][sj];
                    }
                }
            }
            init = std::move(next);
        }

        return init;
    }
};