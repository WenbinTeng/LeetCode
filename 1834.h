#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> getOrder(std::vector<std::vector<int>> &tasks) {
        struct cmp {
            bool operator()(std::vector<int> &a, std::vector<int> &b) { return a[0] != b[0] ? a[0] > b[0] : a[1] > b[1]; };
        };

        std::vector<int> res;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, cmp> waitQueue;
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, cmp> execQueue;

        for (int i = 0; i < tasks.size(); ++i) {
            waitQueue.push({tasks[i][0], tasks[i][1], i});
        }

        long long time = waitQueue.top()[0];

        auto top = waitQueue.top();
        execQueue.push({top[1], top[2]});
        waitQueue.pop();

        while (!waitQueue.empty() || !execQueue.empty()) {
            time = time + execQueue.top()[0];
            res.push_back(execQueue.top()[1]);
            execQueue.pop();

            if (execQueue.empty() && !waitQueue.empty() && waitQueue.top()[0] > time)
                time = waitQueue.top()[0];

            while (!waitQueue.empty() && waitQueue.top()[0] <= time) {
                auto ele = waitQueue.top();
                execQueue.push({ele[1], ele[2]});
                waitQueue.pop();
            }
        }

        return res;
    }
};