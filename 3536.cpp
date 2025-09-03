#include <vector>

class Solution {
  public:
    int maxProduct(int n) {
        auto getDigits = [](int n) -> std::vector<int> {
            std::vector<int> digits;
            while (n) {
                digits.push_back(n % 10);
                n /= 10;
            }
            return digits;
        };

        int res = 0;
        auto digits = getDigits(n);

        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                res = std::max(res, digits[i] * digits[j]);
            }
        }

        return res;
    }
};