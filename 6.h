#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        buff.resize(numRows);
        for (int index = 0;;) {
            for (int i = numRows - 1; i > 0; i--) {
                if (i == numRows - 1) {
                    for (int j = 0; j < numRows; j++) {
                        buff[j].push_back(s[index++]);

                        if (index == s.size()) {
                            return printResult();
                        }
                    }
                } else {
                    buff[i].push_back(s[index++]);

                    if (index == s.size()) {
                        return printResult();
                    }
                }
            }
        }
    }

private:
    std::vector<std::string> buff;

    std::string printResult() {
        std::string temp = "";

        for (auto &iter : buff) {
            temp += iter;
        }

        return temp;
    }
};