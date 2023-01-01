#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> findNumOfValidWords(std::vector<std::string> &words, std::vector<std::string> &puzzles) {
        std::vector<int> res;

        for (auto &word : words)
            ++um[getBin(word)];

        for (auto &puzzle : puzzles)
            res.push_back(getCnt(puzzle));

        return res;
    }

private:
    std::unordered_map<int, int> um;

    int getBin(std::string &w) {
        std::bitset<26> res(0);

        for (const auto &c : w) {
            res[c - 'a'] = 1;
        }

        return res.to_ulong();
    }

    int getCnt(std::string &p) {
        int res = 0;

        for (int i = 0; i < (1 << (p.size() - 1)); ++i) {
            std::bitset<26> rec(1 << (p[0] - 'a'));

            for (int j = 1; j < p.size(); ++j) {
                if (((i >> (j - 1)) & 1) != 0) {
                    rec[p[j] - 'a'] = 1;
                }
            }

            res += um[rec.to_ulong()];
        }

        return res;
    }
};