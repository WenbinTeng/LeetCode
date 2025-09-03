#include <string>

class Solution {
  public:
    int generateKey(int num1, int num2, int num3) {
        auto getNumStr = [](int num) -> std::string {
            std::string ret = std::to_string(num);
            while (ret.size() < 4) {
                ret = "0" + ret;
            }
            return ret;
        };

        std::string s1 = getNumStr(num1);
        std::string s2 = getNumStr(num2);
        std::string s3 = getNumStr(num3);

        std::string s;

        for (int i = 0; i < 4; i++) {
            s.push_back(std::min(s1[i], std::min(s2[i], s3[i])));
        }

        return std::stoi(s);
    }
};