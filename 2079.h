#include <vector>

class Solution {
public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        int res = 0;
        int acc = 0;

        for (int i = 0; i < plants.size(); ++i)
        {
            if (acc + plants[i] > capacity)
            {
                acc = 0;
                res += i * 2;
            }
            acc += plants[i];
            res += 1;
        }

        return res;
    }
};