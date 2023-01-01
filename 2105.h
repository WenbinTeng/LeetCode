#include <vector>

class Solution {
public:
    int minimumRefill(std::vector<int> &plants, int capacityA, int capacityB) {
        int res = 0;

        int posA = 0;
        int posB = plants.size() - 1;
        int capA = capacityA;
        int capB = capacityB;

        while (posA < posB) {
            if (capA < plants[posA]) {
                capA = capacityA;
                ++res;
            }
            if (capB < plants[posB]) {
                capB = capacityB;
                ++res;
            }

            capA -= plants[posA];
            capB -= plants[posB];

            ++posA;
            --posB;
        }

        if (posA == posB) {
            if (std::max(capA, capB) < plants[posA])
                ++res;
        }

        return res;
    }
};