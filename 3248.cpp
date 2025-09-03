#include <string>
#include <vector>

class Solution {
  public:
    int finalPositionOfSnake(int n, std::vector<std::string> &commands) {
        int res = 0;

        for (auto &command : commands) {
            if (command == "UP")
                res -= n;
            else if (command == "RIGHT")
                res += 1;
            else if (command == "DOWN")
                res += n;
            else if (command == "LEFT")
                res -= 1;
        }

        return res;
    }
};