#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> um;
        std::vector<std::string> res;

        for (const auto& word : words)
        {
            ++um[word];
        }

        for (const auto& [s, _] : um)
        {
            res.push_back(s);
        }

        auto cmp = [&](std::string& a, std::string& b) {
            return um[a] == um[b] ? a < b : um[a] > um[b];
        };

        std::sort(res.begin(), res.end(), cmp);

        res.erase(res.begin() + k, res.end());

        return res;
    }
};