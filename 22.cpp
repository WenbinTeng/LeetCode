#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string path(2 * n, 0);

        auto backtrack = [&](auto &&self, int left, int right) -> void {
            if (right == n) {
                res.push_back(path);
                return;
            }
            if (left < n) {
                path[left + right] = '(';
                self(self, left + 1, right);
            }
            if (right < left) {
                path[left + right] = ')';
                self(self, left, right + 1);
            }
        };

        backtrack(backtrack, 0, 0);

        return res;
    }
};