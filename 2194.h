#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> cellsInRange(std::string s) {
        std::vector<std::string> res;
        char col1 = s[0];
        char row1 = s[1];
        char col2 = s[3];
        char row2 = s[4];

        for (char i = col1; i <= col2; ++i) {
            for (char j = row1; j <= row2; ++j) {
                std::string t = "";
                t.push_back(i);
                t.push_back(j);
                res.push_back(t);
            }
        }

        return res;
    }
};