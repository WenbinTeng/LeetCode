#include <string>

class Solution {
  public:
    bool checkRecord(std::string s) {
        int cntA = 0;
        int cntL = 0;
        bool continuousL = false;

        for (auto c : s) {
            if (c == 'A') {
                cntA++;
                cntL = 0;
            } else if (c == 'L') {
                cntL++;
            } else {
                cntL = 0;
            }
            if (cntL >= 3) {
                continuousL = true;
            }
        }

        return cntA < 2 && !continuousL;
    }
};