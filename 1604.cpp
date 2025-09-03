#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::string> alertNames(std::vector<std::string> &keyName,
                                        std::vector<std::string> &keyTime) {
        std::vector<std::string> res;
        std::unordered_map<std::string, std::vector<int>> um;

        for (int i = 0; i < keyName.size(); i++) {
            std::string name = keyName[i];
            std::string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            um[name].push_back(hour * 60 + minute);
        }

        for (auto &[name, list] : um) {
            std::sort(list.begin(), list.end());
            for (int i = 2; i < list.size(); i++) {
                if (list[i] - list[i - 2] <= 60) {
                    res.push_back(name);
                    break;
                }
            }
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};