#include <algorithm>
#include <vector>

class Solution {
public:
    int minimumDifference(std::vector<int> &nums) {
        int n = nums.size();
        int h = n / 2;
        int res = INT_MAX;
        std::vector<int> a;
        std::vector<int> b;
        std::vector<std::vector<int>> rec(h + 1);

        a.assign(nums.begin() + 0, nums.begin() + h);
        b.assign(nums.begin() + h, nums.begin() + n);

        for (int i = 0; i < 1 << h; ++i) {
            long long sum = 0;
            long long cnt = 0;

            for (int j = 0; j < a.size(); ++j) {
                if (i >> j & 1 > 0)
                    sum += a[j], ++cnt;
                else
                    sum -= a[j];
            }

            rec[cnt].push_back(sum);
        }

        for (auto &row : rec)
            std::sort(row.begin(), row.end());

        for (int i = 0; i < 1 << h; ++i) {
            long long sum = 0;
            long long cnt = 0;

            for (int j = 0; j < b.size(); ++j) {
                if (i >> j & 1 > 0)
                    sum += b[j], ++cnt;
                else
                    sum -= b[j];
            }

            int index = std::lower_bound(rec[cnt].begin(), rec[cnt].end(), sum) - rec[cnt].begin();

            if (index < rec[cnt].size())
                res = std::min((long long)res, rec[cnt][index + 0] - sum);
            if (index > 0)
                res = std::min((long long)res, sum - rec[cnt][index - 1]);
        }

        return res;
    }
};