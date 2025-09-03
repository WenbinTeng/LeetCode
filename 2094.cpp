#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    std::vector<int> findEvenNumbers(std::vector<int> &digits) {
        std::vector<int> res;
        std::unordered_set<int> num;

        for (int i = 0; i < digits.size(); ++i) {
            for (int j = i + 1; j < digits.size(); ++j) {
                for (int k = j + 1; k < digits.size(); ++k) {
                    int a = digits[i] * 100 + digits[j] * 10 + digits[k];
                    int b = digits[i] * 100 + digits[k] * 10 + digits[j];
                    int c = digits[j] * 100 + digits[i] * 10 + digits[k];
                    int d = digits[j] * 100 + digits[k] * 10 + digits[i];
                    int e = digits[k] * 100 + digits[i] * 10 + digits[j];
                    int f = digits[k] * 100 + digits[j] * 10 + digits[i];

                    if (digits[i]) {
                        if (a % 2 == 0)
                            num.insert(a);
                        if (b % 2 == 0)
                            num.insert(b);
                    }
                    if (digits[j]) {
                        if (c % 2 == 0)
                            num.insert(c);
                        if (d % 2 == 0)
                            num.insert(d);
                    }
                    if (digits[k]) {
                        if (e % 2 == 0)
                            num.insert(e);
                        if (f % 2 == 0)
                            num.insert(f);
                    }
                }
            }
        }

        for (const auto n : num) {
            res.push_back(n);
        }

        std::sort(res.begin(), res.end());

        return res;
    }
};