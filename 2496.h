#include <vector>
#include <string>

class Solution {
public:
    int maximumValue(std::vector<std::string>& strs) {
        int res = 0;

        for (auto &str : strs) {
            bool onlyNum = true;
            for (auto &c : str) {
                if (c < '0' || c > '9') {
                    onlyNum = false;
                    break;
                }
            }
            res = std::max(res, (int)(onlyNum ? std::stoi(str) : str.size()));
        }

        return res;
    }
};