#include <string>

class Solution {
  public:
    int convertTime(std::string current, std::string correct) {
        int res = 0;
        int srcH = std::stoi(current.substr(0, 2));
        int srcM = std::stoi(current.substr(3, 2));
        int dstH = std::stoi(correct.substr(0, 2));
        int dstM = std::stoi(correct.substr(3, 2));

        res += dstH - srcH;

        if (dstM < srcM) {
            dstM += 60;
            --res;
        }

        while (dstM - srcM >= 15) {
            srcM += 15;
            ++res;
        }

        while (dstM - srcM >= 5) {
            srcM += 5;
            ++res;
        }

        while (dstM - srcM >= 1) {
            srcM += 1;
            ++res;
        }

        return res;
    }
};