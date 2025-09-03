#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::string destCity(std::vector<std::vector<std::string>> &paths) {
        std::unordered_map<std::string, std::string> dict;

        for (auto &path : paths) {
            auto &city1 = path[0];
            auto &city2 = path[1];
            dict[city1] = city2;
        }

        auto &src = paths[0][0];
        while (dict.count(src)) {
            src = dict[src];
        }

        return src;
    }
};