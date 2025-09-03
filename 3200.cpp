#include <vector>

class Solution {
  public:
    int maxHeightOfTriangle(int red, int blue) {
        auto check = [&](int oddCnt, int evenCnt) -> int {
            for (int i = 1; i <= 20; i++) {
                if (i % 2 == 0) {
                    if (oddCnt < i)
                        return i - 1;
                    else
                        oddCnt -= i;
                } else {
                    if (evenCnt < i)
                        return i - 1;
                    else
                        evenCnt -= i;
                }
            }
            return 0;
        };

        return std::max(check(red, blue), check(blue, red));
    }
};