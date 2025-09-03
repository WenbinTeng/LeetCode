#include <string>
#include <vector>

class Solution {
  public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice,
                          std::string arriveBob, std::string leaveBob) {
        int res = 0;

        for (int i = 1; i < days.size(); i++) {
            days[i] += days[i - 1];
        }

        int aliceArriveDays = getDays(arriveAlice);
        int aliceLeaveDays = getDays(leaveAlice);
        int bobArriveDays = getDays(arriveBob);
        int bobLeaveDays = getDays(leaveBob);

        return std::max(0, std::min(aliceLeaveDays, bobLeaveDays) -
                               std::max(aliceArriveDays, bobArriveDays) + 1);
    }

  private:
    std::vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int getDays(std::string &s) {
        int month = std::stoi(s.substr(0, 2));
        int day = std::stoi(s.substr(3, 2));
        return days[month - 1] + day;
    }
};