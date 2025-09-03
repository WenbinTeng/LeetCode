#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    long long maxWeight(std::vector<int> &pizzas) {
        int n = pizzas.size();
        int m = n / 4;
        int ptr = n;
        long long res = 0;

        std::sort(pizzas.begin(), pizzas.end());

        for (int i = 1; i <= (m + 1) / 2; i++)
            ptr--, res += pizzas[ptr];
        for (int i = 1; i <= m / 2; i++)
            ptr -= 2, res += pizzas[ptr];

        return res;
    }
};