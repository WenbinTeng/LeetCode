#include <map>
#include <vector>

class Solution {
  public:
    long long
    interchangeableRectangles(std::vector<std::vector<int>> &rectangles) {
        long long res = 0;

        std::map<double, long long> m;
        for (auto r : rectangles) {
            m[(double)r[1] / (double)r[0]]++;
        }

        for (auto p : m) {
            if (p.second <= 1) {
                continue;
            } else {
                res += p.second * (p.second - 1) / 2;
            }
        }

        return res;
    }
};