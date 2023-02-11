#include <algorithm>
#include <vector>

class Solution {
public:
    int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
        int res = 0;
        std::vector<int> cnt(n);
        std::vector<long long> time(n);

        std::sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings) {
            int best = 0;
            bool allocated = false;

            for (int i = 0; i < n; i++) {
                if (time[i] <= meeting[0]) {
                    cnt[i]++;
                    time[i] = meeting[1];
                    allocated = true;
                } else if (time[i] < time[best]) {
                    best = i;
                }
                if (allocated)
                    break;
            }
            if (allocated)
                continue;

            cnt[best]++;
            time[best] += meeting[1] - meeting[0];
        }

        for (int i = 0; i < n; i++) {
            if (cnt[i] > cnt[res]) {
                res = i;
            }
        }

        return res;
    }
};