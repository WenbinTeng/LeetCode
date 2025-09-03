#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int scoreOfStudents(std::string s, std::vector<int> &answers) {
        int res = 0;
        int ans = getAnswer(s);

        for (const auto &c : s) {
            if (c == '+' || c == '*') {
                _operator.push_back(c);
            } else {
                _operands.push_back(c);
            }
        }

        seq = std::vector<std::vector<std::unordered_set<int>>>(
            _operands.size(),
            std::vector<std::unordered_set<int>>(_operands.size(),
                                                 std::unordered_set<int>({})));

        dfs(0, _operands.size() - 1);

        auto &rec = seq[0][_operands.size() - 1];

        for (const auto &answer : answers) {
            res += answer == ans ? 5 : rec.count(answer) ? 2 : 0;
        }

        return res;
    }

  private:
    std::vector<char> _operands;
    std::vector<char> _operator;
    std::vector<std::vector<std::unordered_set<int>>> seq;

    void dfs(int l, int r) {
        if (!seq[l][r].empty())
            return;

        if (l == r) {
            seq[l][r] = std::unordered_set<int>({_operands[l] - '0'});
            return;
        }

        std::unordered_set<int> res;

        for (int i = l; i < r; ++i) {
            dfs(l, i + 0);
            dfs(i + 1, r);

            for (const auto &nl : seq[l][i + 0]) {
                for (const auto &nr : seq[i + 1][r]) {
                    if (_operator[i] == '+' && nl + nr <= 1000)
                        res.insert(nl + nr);
                    if (_operator[i] == '*' && nl * nr <= 1000)
                        res.insert(nl * nr);
                }
            }
        }

        seq[l][r] = res;
    }

    int getAnswer(std::string s) {
        std::vector<int> nums = {s[0] - '0'};

        for (int i = 1; i < s.size() - 1; i += 2) {
            if (s[i] == '*') {
                nums.back() *= (s[i + 1] - '0');
            } else {
                nums.push_back(s[i + 1] - '0');
            }
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};