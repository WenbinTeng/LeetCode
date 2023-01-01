#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

class Solution {
public:
    int minimumTimeRequired(std::vector<int> &jobs, int k) {
        std::sort(jobs.begin(), jobs.end(), std::greater<int>());

        int l = jobs[0];
        int r = std::accumulate(jobs.begin(), jobs.end(), 0);
        std::vector<int> workloads(k, 0);

        while (l < r) {
            int mid = (l + r) / 2;

            if (dfs(jobs, workloads, 0, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }

            workloads = std::vector<int>(k, 0);
        }

        return l;
    }

private:
    bool dfs(std::vector<int> &jobs, std::vector<int> &workloads, int index, int limit) {
        if (index >= jobs.size())
            return true;

        int curr = jobs[index];

        for (auto &workload : workloads) {
            if (workload + curr <= limit) {
                workload += curr;
                if (dfs(jobs, workloads, index + 1, limit))
                    return true;
                workload -= curr;
            }

            if (workload == 0 || workload + curr == limit)
                break;
        }

        return false;
    }
};