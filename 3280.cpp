#include <algorithm>
#include <string>

class Solution {
  public:
    std::string convertDateToBinary(std::string date) {
        std::string res;
        date.push_back('-');
        for (int i = 0, start = 0; i < date.size(); i++) {
            if (date[i] == '-') {
                res += dec2bin(date.substr(start, i - start)) + "-";
                start = i + 1;
            }
        }
        res.pop_back();
        return res;
    }

  private:
    std::string dec2bin(std::string s) {
        std::string binStr;
        int num = std::stoi(s);
        while (num) {
            binStr.push_back((num % 2) + '0');
            num /= 2;
        }
        std::reverse(binStr.begin(), binStr.end());
        return binStr;
    }
};