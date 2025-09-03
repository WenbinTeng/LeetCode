#include <queue>
#include <vector>

class Solution {
  public:
    double maxAverageRatio(std::vector<std::vector<int>> &classes,
                           int extraStudents) {
        double res = 0;
        std::priority_queue<std::pair<double, int>> pq;

        for (int i = 0; i < classes.size(); ++i) {
            double oriRatio =
                (double)(classes[i][0] + 0) / (double)(classes[i][1] + 0);
            double addRatio =
                (double)(classes[i][0] + 1) / (double)(classes[i][1] + 1);
            pq.push(std::make_pair(addRatio - oriRatio, i));
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto [ratio, index] = pq.top();
            pq.pop();

            ++classes[index][0];
            ++classes[index][1];

            double oriRatio = (double)(classes[index][0] + 0) /
                              (double)(classes[index][1] + 0);
            double addRatio = (double)(classes[index][0] + 1) /
                              (double)(classes[index][1] + 1);

            pq.push(std::make_pair(addRatio - oriRatio, index));
        }

        for (res = 0; !pq.empty(); pq.pop()) {
            res += (double)classes[pq.top().second][0] /
                   (double)classes[pq.top().second][1];
        }

        return res / classes.size();
    }
};