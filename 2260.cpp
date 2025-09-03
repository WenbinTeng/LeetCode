#include <unordered_map>
#include <vector>

class Solution {
  public:
    int minimumCardPickup(std::vector<int> &cards) {
        int res = cards.size();
        bool finded = false;
        std::unordered_map<int, int> minMap;
        std::unordered_map<int, int> idxMap;

        for (int i = 0; i < cards.size(); ++i) {
            minMap[cards[i]] = cards.size();
        }

        for (int i = 0; i < cards.size(); ++i) {
            if (idxMap.count(cards[i])) {
                finded = true;
                minMap[cards[i]] =
                    std::min(minMap[cards[i]], i - idxMap[cards[i]] + 1);
            }
            idxMap[cards[i]] = i;
        }

        for (const auto [_, min] : minMap) {
            res = std::min(res, min);
        }

        return finded ? res : -1;
    }
};