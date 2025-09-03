#include <algorithm>
#include <vector>

class Solution {
  public:
    bool asteroidsDestroyed(int mass, std::vector<int> &asteroids) {
        std::vector<long long> copy(asteroids.size());

        std::sort(asteroids.begin(), asteroids.end());

        for (int i = 0; i < asteroids.size(); ++i) {
            copy[i] = asteroids[i];
        }

        if (mass < copy.front())
            return false;
        else
            copy[0] += mass;

        for (int i = 1; i < copy.size(); ++i) {
            if (copy[i - 1] < copy[i])
                return false;
            else
                copy[i] += copy[i - 1];
        }

        return true;
    }
};