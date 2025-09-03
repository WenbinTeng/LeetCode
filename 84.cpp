#include <stack>
#include <vector>

class Solution {
  public:
    int largestRectangleArea(std::vector<int> &heights) {
        if (heights.empty())
            return 0;

        int res = 0;
        int n = heights.size();
        std::vector<int> lBoarder(n);
        std::vector<int> rBoarder(n);
        std::stack<int> s;

        while (!s.empty())
            s.pop();
        for (int i = 0; i <= n - 1; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            lBoarder[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            rBoarder[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            res = std::max(res, heights[i] * (rBoarder[i] - lBoarder[i] - 1));
        }

        return res;
    }
};