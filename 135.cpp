#include <vector>

class Solution {
  public:
    int candy(std::vector<int> &ratings) {
        std::vector<int> left(ratings.size());
        int right;
        int res;

        left[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }

        right = 1;
        res = std::max(left.back(), right);
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            res += std::max(left[i], right);
        }

        return res;
    }
};