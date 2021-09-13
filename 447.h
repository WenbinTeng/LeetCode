#include <vector>
#include <map>

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
        int res = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            std::map<int, int> m;

            for (int j = 0; j < points.size(); ++j)
            {
                if (i != j)
                {
                    m[(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])]++;
                }
            }

            for (const auto item : m)
            {
                res += item.second * (item.second - 1);
            }
        }

        return res;
    }
};