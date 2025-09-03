#include <vector>

class Solution {
  public:
    int busyStudent(std::vector<int> &startTime, std::vector<int> &endTime,
                    int queryTime) {
        int res = 0;

        for (int i = 0; i < startTime.size(); ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                ++res;
            }
        }

        return res;
    }
};