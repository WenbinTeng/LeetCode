#include <map>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>> &items1, std::vector<std::vector<int>> &items2) {
        std::vector<std::vector<int>> res;
        std::map<int, int> m;

        for (const auto &item : items1) {
            m[item[0]] += item[1];
        }

        for (const auto &item : items2) {
            m[item[0]] += item[1];
        }

        while (!m.empty()) {
            auto [k, v] = *m.begin();
            res.push_back({k, v});
            m.erase(m.begin());
        }

        return res;
    }
};