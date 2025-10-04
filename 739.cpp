#include <stack>
#include <vector>

class Solution {
  public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        const int n = temperatures.size();
        std::vector<int> res(n);
        std::stack<int> monoStack;

        for (int i = 0; i < n; i++) {
            while (!monoStack.empty() &&
                   temperatures[i] > temperatures[monoStack.top()]) {
                int j = monoStack.top();
                res[j] = i - j;
                monoStack.pop();
            }
            monoStack.push(i);
        }

        return res;
    }
};