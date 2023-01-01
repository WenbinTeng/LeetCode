#include <vector>

class Solution {
public:
    int maxScore(std::vector<int> &cardPoints, int k) {
        int minValue = 0;
        int curValue = 0;
        int n = cardPoints.size();
        int sum = 0;

        for (const auto &iter : cardPoints)
            sum += iter;

        for (int i = 0; i < n - k; i++) {
            minValue += cardPoints[i];
            curValue += cardPoints[i];
        }

        for (int i = n - k; i < n; i++) {
            curValue += cardPoints[i];
            curValue -= cardPoints[i - (n - k)];
            minValue = std::min(minValue, curValue);
        }

        return sum - minValue;
    }
};