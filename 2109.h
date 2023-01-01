#include <string>
#include <vector>

class Solution {
public:
    std::string addSpaces(std::string s, std::vector<int> &spaces) {
        std::string res = "";

        res += s.substr(0, spaces[0]);

        for (int i = 1; i < spaces.size(); ++i) {
            res += " " + s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]);
        }

        res += " " + s.substr(spaces.back());

        return res;
    }
};