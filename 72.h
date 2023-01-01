#include <string>
#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int res = 0;
        int n1 = word1.size();
        int n2 = word2.size();
        std::vector<std::vector<bool>> vis(n1 + 1, std::vector<bool>(n2 + 1, false));
        std::vector<std::pair<int, int>> rec(1, std::make_pair(0, 0));

        while (true) {
            std::vector<std::pair<int, int>> buffer;

            for (auto &[i1, i2] : rec) {
                if (word1.substr(i1, n1 - i1) == word2.substr(i2, n2 - i2))
                    return res;

                while (i1 < n1 && i2 < n2 && word1[i1] == word2[i2]) {
                    ++i1;
                    ++i2;
                }

                if (i1 < n1 && !vis[i1 + 1][i2]) {
                    buffer.push_back(std::make_pair(i1 + 1, i2));
                    vis[i1 + 1][i2] = true;
                }
                if (i2 < n2 && !vis[i1][i2 + 1]) {
                    buffer.push_back(std::make_pair(i1, i2 + 1));
                    vis[i1][i2 + 1] = true;
                }
                if (i1 < n1 && i2 < n2 && !vis[i1 + 1][i2 + 1]) {
                    buffer.push_back(std::make_pair(i1 + 1, i2 + 1));
                    vis[i1 + 1][i2 + 1] = true;
                }
            }
            rec = std::move(buffer);

            ++res;
        }

        return res;
    }
};