#include <algorithm>
#include <vector>

class Solution {
  public:
    int maximumScore(int a, int b, int c) { return dfs(a, b, c, 0); }

  private:
    int dfs(int a, int b, int c, int score) {
        if (a < 0 || b < 0 || c < 0)
            return score - 1;

        std::vector<int> numVec = {a, b, c};
        std::vector<int>::iterator iter;

        iter = std::max_element(numVec.begin(), numVec.end());
        int maxValue = *iter;
        numVec.erase(iter);
        iter = std::min_element(numVec.begin(), numVec.end());
        int minValue = *iter;
        numVec.erase(iter);

        return minValue == 0
                   ? dfs(maxValue - 1, minValue, numVec[0] - 1, score + 1)
                   : dfs(maxValue - 1, minValue - 1, numVec[0], score + 1);
    }
};