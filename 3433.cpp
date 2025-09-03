#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<int>
    countMentions(int numberOfUsers,
                  std::vector<std::vector<std::string>> &events) {
        std::vector<int> res(numberOfUsers, 0);
        std::vector<int> onlineTimeStamp(numberOfUsers, 0);

        std::sort(events.begin(), events.end(),
                  [](std::vector<std::string> &a, std::vector<std::string> &b) {
                      int ta = std::stoi(a[1]);
                      int tb = std::stoi(b[1]);
                      if (ta == tb)
                          return a[0] == "OFFLINE";
                      return ta < tb;
                  });

        for (auto &event : events) {
            if (event[0] == "MESSAGE") {
                int timeStamp = std::stoi(event[1]);
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        res[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (onlineTimeStamp[i] <= timeStamp) {
                            res[i]++;
                        }
                    }
                } else {
                    std::istringstream iss(event[2]);
                    std::string strBuff;
                    std::vector<int> users;
                    while (iss >> strBuff) {
                        int mentionedId = std::stoi(strBuff.substr(2));
                        res[mentionedId]++;
                    }
                }
            } else if (event[0] == "OFFLINE") {
                int timeStamp = std::stoi(event[1]);
                int mentionedId = std::stoi(event[2]);
                onlineTimeStamp[mentionedId] = timeStamp + 60;
            }
        }

        return res;
    }
};