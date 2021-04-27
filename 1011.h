#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int D) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r =  std::accumulate (weights.begin(), weights.end(), 0);

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (isValid(weights, D, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return r;
    }

private:
    bool isValid(std::vector<int>& weights, int D, int cap)
    {
        int cnt = 0;
        int sum = 0;
        
        for (const auto& w : weights)
        {
            if (sum + w > cap)
            {
                sum  = w;
                cnt += 1;
            }
            else
            {
                sum += w;
            }
        }

        if (sum > 0) ++cnt;

        return cnt <= D;
    }
};