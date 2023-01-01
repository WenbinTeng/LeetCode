#include <vector>

class Solution {
public:
    long long mostPoints(std::vector<std::vector<int>> &questions) {
        long long res = 0;
        std::vector<long long> dp(questions.size() + 1);

        for (int i = 0; i < questions.size(); ++i) {
            dp[i + 1] = std::max(dp[i], dp[i + 1]);
            int next = std::min(i + 1 + questions[i][1], (int)questions.size());
            dp[next] = std::max(dp[next], dp[i] + questions[i][0]);
        }

        return dp[questions.size()];
    }
};