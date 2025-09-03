#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string>
    validateCoupons(std::vector<std::string> &code,
                    std::vector<std::string> &businessLine,
                    std::vector<bool> &isActive) {
        const int n = code.size();
        std::vector<std::string> res;
        std::vector<std::pair<std::string, std::string>> container;

        auto validCode = [](std::string &code) -> bool {
            if (code.empty())
                return false;
            for (auto c : code) {
                if (!std::isalpha(c) && !std::isdigit(c) && (c != '_'))
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (validCode(code[i]) && isActive[i] &&
                (businessLine[i] == "electronics" ||
                 businessLine[i] == "grocery" ||
                 businessLine[i] == "pharmacy" ||
                 businessLine[i] == "restaurant")) {
                container.push_back({businessLine[i], code[i]});
            }
        }

        std::sort(container.begin(), container.end());

        for (auto &[b, c] : container) {
            res.push_back(c);
        }

        return res;
    }
};