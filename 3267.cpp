#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    int countPairs(std::vector<int> &nums) {
        int res = 0;
        std::unordered_map<int, int> numCnt;

        for (auto num : nums) {
            std::vector<int> rec;
            std::vector<int> digits = std::move(getDigits(num));

            for (int l = 0; l < MAX_DIGIT; l++) {
                for (int r = l + 1; r < MAX_DIGIT; r++) {
                    std::swap(digits[l], digits[r]);
                    rec.push_back(spellDigits(digits));
                    for (int ll = 0; ll < MAX_DIGIT; ll++) {
                        for (int rr = ll + 1; rr < MAX_DIGIT; rr++) {
                            std::swap(digits[ll], digits[rr]);
                            rec.push_back(spellDigits(digits));
                            std::swap(digits[ll], digits[rr]);
                        }
                    }
                    std::swap(digits[l], digits[r]);
                }
            }

            rec.push_back(num);
            std::sort(rec.begin(), rec.end());
            rec.resize(std::unique(rec.begin(), rec.end()) - rec.begin());
            for (auto swappedNum : rec) {
                if (numCnt.count(swappedNum)) {
                    res += numCnt[swappedNum];
                }
            }

            numCnt[num]++;
        }

        return res;
    }

  private:
    const int MAX_DIGIT = 7;

    std::vector<int> getDigits(int n) {
        std::vector<int> digits(MAX_DIGIT, 0);
        for (int i = 0; i < MAX_DIGIT; i++) {
            digits[i] = n % 10;
            n /= 10;
        }
        return digits;
    }

    int spellDigits(std::vector<int> &digits) {
        int n = 0;
        for (int i = 0; i < MAX_DIGIT; i++) {
            n = n * 10 + digits[MAX_DIGIT - 1 - i];
        }
        return n;
    }
};