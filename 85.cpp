#include <stack>
#include <vector>

class Solution {
  public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        if (matrix.empty())
            return 0;

        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> line(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                line[j] = matrix[i][j] == '0' ? 0 : line[j] + 1;
            }

            std::vector<int> lBoarder(n);
            std::vector<int> rBoarder(n);
            std::stack<int> s;

            while (!s.empty())
                s.pop();
            for (int j = 0; j <= n - 1; j++) {
                while (!s.empty() && line[s.top()] >= line[j])
                    s.pop();
                lBoarder[j] = s.empty() ? -1 : s.top();
                s.push(j);
            }

            while (!s.empty())
                s.pop();
            for (int j = n - 1; j >= 0; j--) {
                while (!s.empty() && line[s.top()] >= line[j])
                    s.pop();
                rBoarder[j] = s.empty() ? n : s.top();
                s.push(j);
            }

            for (int j = 0; j < n; j++) {
                res = std::max(res, line[j] * (rBoarder[j] - lBoarder[j] - 1));
            }
        }

        return res;
    }
};