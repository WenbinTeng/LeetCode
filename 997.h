#include <vector>

class Solution {
public:
    int findJudge(int N, std::vector<std::vector<int>> &trust) {
        if (N == 1)
            return 1;

        std::vector<int> trustIn(N + 1, 0);
        std::vector<int> beTrust(N + 1, 0);
        int res = -1;

        for (const auto &trustPair : trust) {
            ++trustIn[trustPair[0]];
            ++beTrust[trustPair[1]];
        }

        for (int i = 0; i <= N; ++i) {
            if (trustIn[i] == 0 && beTrust[i] == N - 1) {
                if (res == -1)
                    res = i;
                else
                    return -1;
            }
        }

        return res;
    }
};