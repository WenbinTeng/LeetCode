#include <stack>

class Solution {
  public:
    int alternateDigitSum(int n) {
        int res = 0;
        int sign = 1;
        std::stack<int> s;

        for (int i = n; i > 0; i /= 10)
            s.push(i % 10);

        while (!s.empty()) {
            res += s.top() * sign;
            sign *= -1;
            s.pop();
        }

        return res;
    }
};