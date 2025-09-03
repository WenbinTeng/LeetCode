#include <vector>

class Solution {
  public:
    int buttonWithLongestTime(std::vector<std::vector<int>> &events) {
        int maxIndex = events[0][0];
        int maxTime = events[0][1];

        for (int i = 1; i < events.size(); i++) {
            int time = events[i][1] - events[i - 1][1];
            if (maxTime < time) {
                maxTime = time;
                maxIndex = events[i][0];
            } else if (maxTime == time) {
                maxIndex = std::min(maxIndex, events[i][0]);
            }
        }

        return maxIndex;
    }
};