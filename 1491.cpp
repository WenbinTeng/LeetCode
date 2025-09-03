#include <vector>

class Solution {
  public:
    double average(std::vector<int> &salary) {
        int sum = 0;
        int maxValue = -INT_MAX + 1;
        int minValue = INT_MAX;

        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            maxValue = std::max(maxValue, salary[i]);
            minValue = std::min(minValue, salary[i]);
        }

        sum -= maxValue;
        sum -= minValue;

        return (double)sum / (salary.size() - 2);
    }
};