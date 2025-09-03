#include <vector>

class Solution {
  public:
    std::vector<int> maximumBobPoints(int numArrows,
                                      std::vector<int> &aliceArrows) {
        std::vector<int> path;
        dfs(aliceArrows, path, numArrows, 0, 0);
        return res;
    }

  private:
    int max = 0;
    std::vector<int> res;

    void dfs(std::vector<int> &aliceArrows, std::vector<int> &path,
             int restArrows, int index, int score) {
        if (index == aliceArrows.size()) {
            path[0] = restArrows;
            if (max < score) {
                max = score;
                res = path;
            }
            return;
        }
        if (index == 0) {
            path.push_back(0);
            dfs(aliceArrows, path, restArrows, index + 1, score);
            return;
        }

        if (restArrows > aliceArrows[index]) {
            path.push_back(aliceArrows[index] + 1);
            dfs(aliceArrows, path, restArrows - aliceArrows[index] - 1,
                index + 1, score + index);
            path.pop_back();
        }
        path.push_back(0);
        dfs(aliceArrows, path, restArrows, index + 1, score);
        path.pop_back();
    }
};