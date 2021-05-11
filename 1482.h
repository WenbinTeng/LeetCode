#include <vector>
#include <algorithm>

class Solution {
public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if (m * k > bloomDay.size()) return -1;

        int l = 0;
        int r = *std::max_element(bloomDay.begin(), bloomDay.end());

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (check(bloomDay, mid, m, k))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }

private:
    bool check(std::vector<int>& bloomDay, int days, int m, int k)
    {
        int tm = 0;
        int tk = 0;
        
        for (const auto& day : bloomDay)
        {
            if (day <= days)
            {
                if (++tk == k)
                {
                    if (++tm == m) return true;
                    tk = 0;
                }
            }
            else
            {
                tk = 0;
            }
        }

        return false;
    }
};