#include <algorithm>
#include <string>
#include <vector>

class Solution {
  public:
    std::string bestHand(std::vector<int> &ranks, std::vector<char> &suits) {
        if (suits[0] == suits[1] && suits[1] == suits[2] &&
            suits[2] == suits[3] && suits[3] == suits[4]) {
            return "Flush";
        } else {
            std::vector<int> cnt(14, 0);
            for (const auto &rank : ranks)
                cnt[rank]++;
            int max = *std::max_element(cnt.begin(), cnt.end());

            if (max >= 3)
                return "Three of a Kind";
            else if (max == 2)
                return "Pair";
            else
                return "High Card";
        }
        return "";
    }
};