#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        const int n = s.size();
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> path;
        std::vector<std::vector<int>> f(n, std::vector<int>(n, true));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        auto backtrack = [&](auto &&self, int index) -> void {
            if (index == n) {
                res.push_back(path);
                return;
            }
            for (int j = index; j < n; j++) {
                if (f[index][j]) {
                    path.push_back(s.substr(index, j - index + 1));
                    self(self, j + 1);
                    path.pop_back();
                }
            }
        };

        backtrack(backtrack, 0);

        return res;
    }
};