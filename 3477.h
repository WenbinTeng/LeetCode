#include <vector>

class Solution {
public:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        int res = 0;
        std::vector<int> placed(baskets.size(), 0);

        for (int i = 0; i < fruits.size(); i++) {
            bool place = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (baskets[j] >= fruits[i] && placed[j] == 0) {
                    placed[j] = 1;
                    place = true;
                    break;
                }
            }
            if (!place)
                res++;
        }

        return res;
    }
};