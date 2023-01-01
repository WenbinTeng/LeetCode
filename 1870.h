#include <cmath>
#include <numeric>
#include <vector>

class Solution {
public:
    int minSpeedOnTime(std::vector<int> &dist, double hour) {
        if (dist.size() > hour + 1)
            return -1;

        int res = -1;
        int l = 1;
        int r = INT_MAX;

        while (l <= r) {
            int mid = ((long long)l + (long long)r) / 2;

            if (check(dist, mid, hour)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

private:
    bool check(std::vector<int> &dist, int speed, double hour) {
        int time = 0;

        for (int i = 0; i < dist.size() - 1; ++i) {
            time += std::ceil((double)dist[i] / (double)speed);
            if (time > hour)
                return false;
        }

        return (time + (double)dist.back() / (double)speed) <= hour;
    }
};