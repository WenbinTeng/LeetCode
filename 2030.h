#include <queue>
#include <string>
#include <vector>

class Solution {
public:
    std::string smallestSubsequence(std::string s, int k, char letter, int repetition) {
        int n = s.size();
        int last = -1;
        std::vector<int> rem(n);
        std::vector<std::queue<int>> pos(26);
        std::string res;

        for (int i = n - 2; i >= 0; --i) {
            rem[i] = rem[i + 1] + (s[i + 1] == letter);
        }

        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].push(i);
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 26; ++j) {
                while (!pos[j].empty() && pos[j].front() < last)
                    pos[j].pop();

                int need = (j == letter - 'a') ? repetition - 1 : repetition;

                if (!pos[j].empty() && rem[pos[j].front()] >= need && k - 1 - i >= need && n - 1 - pos[j].front() >= k - 1 - i) {
                    res.push_back('a' + j);
                    if (j == letter - 'a')
                        repetition--;
                    last = pos[j].front();
                    pos[j].pop();
                    break;
                }
            }
        }
        return res;
    }
};