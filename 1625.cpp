#include <string>
#include <vector>

class Solution {
  public:
    std::string findLexSmallestString(std::string s, int a, int b) {
        std::string res = s;
        std::vector<int> visited(s.size());
        int n = s.size();
        s = s + s;

        for (int i = 0; visited[i] == 0; i = (i + b) % n) {
            visited[i] = 1;
            for (int j = 0; j < 10; j++) {
                int limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= limit; k++) {
                    std::string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = std::min(res, t);
                }
            }
        }

        return res;
    }
};