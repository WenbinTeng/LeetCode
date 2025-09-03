#include <string>
#include <vector>

class Solution {
  public:
    int numOfStrings(std::vector<std::string> &patterns, std::string word) {
        int res = 0;

        for (const auto &pattern : patterns) {
            if (word.find(pattern) != std::string::npos) {
                res++;
            }
        }

        return res;
    }
};