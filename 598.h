#include <vector>

class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        int mina = m;
        int minb = n;

        for (auto& op : ops) {
            mina = std::min(mina, op[0]);
            minb = std::min(minb, op[1]);
        }

        return mina * minb;
    }
};