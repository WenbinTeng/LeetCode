#include <algorithm>
#include <vector>

class Solution {
public:
    int largestInteger(int num) {
        int res = 0;
        std::vector<int> digits;
        std::vector<int> odd;
        std::vector<int> even;

        while (num) {
            int digit = num % 10;

            digits.push_back(digit);

            if (digit & 1) {
                even.push_back(digit);
            } else {
                odd.push_back(digit);
            }

            num /= 10;
        }

        std::sort(odd.begin(), odd.end(), std::greater<int>());
        std::sort(even.begin(), even.end(), std::greater<int>());

        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] & 1) {
                digits[i] = even.back();
                even.pop_back();
            } else {
                digits[i] = odd.back();
                odd.pop_back();
            }
        }

        while (!digits.empty()) {
            res = res * 10 + digits.back();
            digits.pop_back();
        }

        return res;
    }
};