#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> assignTasks(std::vector<int> &servers, std::vector<int> &tasks) {
        std::vector<int> res(tasks.size());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> idle;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> busy;

        for (int i = 0; i < servers.size(); ++i) {
            idle.push({servers[i], i});
        }

        int timer = 0;
        int index = 0;

        while (index < tasks.size()) {
            while (index < tasks.size() && index <= timer && !idle.empty()) {
                auto server = idle.top();
                idle.pop();
                busy.push({timer + tasks[index], server.second});
                res[index] = server.second;
                ++index;
            }

            timer = !idle.empty() ? timer + 1 : busy.top().first;

            while (!busy.empty()) {
                auto server = busy.top();
                if (server.first <= timer) {
                    busy.pop();
                    idle.push({servers[server.second], server.second});
                } else {
                    break;
                }
            }
        }

        return res;
    }
};