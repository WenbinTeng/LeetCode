#include <limits.h>
#include <vector>

class Solution {
public:
    long long minimumTime(std::vector<int> &time, int totalTrips) {
        long long l = 0;
        long long r = LONG_LONG_MAX;

        while (l < r) {
            long long mid = l + (r - l) / 2;

            if (getTrips(time, totalTrips, mid) < totalTrips) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return r;
    }

private:
    long long getTrips(std::vector<int> &time, int totalTrips, long long timeStamp) {
        long long trips = 0;

        for (const auto t : time) {
            trips += timeStamp / t;

            if (trips >= totalTrips)
                return trips;
        }

        return trips;
    }
};