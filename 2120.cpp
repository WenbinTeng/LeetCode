#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int> executeInstructions(int n, std::vector<int> &startPos,
                                         std::string s) {
        std::vector<int> res(s.size(), 0);

        for (int i = 0; i < s.size(); ++i) {
            int cnt = 0;
            int x = startPos[1];
            int y = startPos[0];

            for (int j = i; j < s.size(); ++j) {
                switch (s[j]) {
                case 'L':
                    --x;
                    break;
                case 'R':
                    ++x;
                    break;
                case 'U':
                    --y;
                    break;
                case 'D':
                    ++y;
                    break;
                default:
                    break;
                }

                if (x < 0 || x >= n || y < 0 || y >= n)
                    break;

                ++cnt;
            }

            res[i] = cnt;
        }

        return res;
    }
};