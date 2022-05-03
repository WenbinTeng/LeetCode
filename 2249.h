#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    int countLatticePoints(std::vector<std::vector<int>>& circles) {
        int res = 0;
        int max = 0;

        for (const auto circle : circles)
        {
            max = std::max(max, std::min(circle[0], circle[1]));
        }

        max *= 2;

        for (int i = 0; i <= max; ++i)
        {
            for (int j = 0; j <= max; ++j)
            {
                for (const auto& circle : circles)
                {
                    int x = circle[0];
                    int y = circle[1];
                    int r = circle[2];

                    if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
                    {
                        ++res;
                        break;
                    }
                }
            }
        }

        return res;
    }
};