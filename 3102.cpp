#include <set>
#include <vector>

class Solution {
  public:
    int minimumDistance(std::vector<std::vector<int>> &points) {
        int res = INT_MAX;
        std::multiset<int> distA;
        std::multiset<int> distB;

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];
            distA.insert(x + y);
            distB.insert(x - y);
        }

        for (auto &point : points) {
            int x = point[0];
            int y = point[1];
            int a = x + y;
            int b = x - y;

            distA.erase(distA.find(a));
            distB.erase(distB.find(b));

            int da = *distA.rbegin() - *distA.begin();
            int db = *distB.rbegin() - *distB.begin();
            res = std::min(res, std::max(da, db));

            distA.insert(a);
            distB.insert(b);
        }

        return res;
    }
};