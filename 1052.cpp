#include <vector>

class Solution {
  public:
    int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy,
                     int X) {
        int res = 0;
        int sum = 0;

        if (X > customers.size())
            X = customers.size();

        for (int i = 0; i < X; ++i) {
            sum += customers[i];
        }

        for (int i = X; i < customers.size(); ++i) {
            sum += grumpy[i] ? 0 : customers[i];
        }

        res = sum;

        for (int i = X; i < customers.size(); ++i) {
            sum -= grumpy[i - X] ? customers[i - X] : 0;
            sum += grumpy[i] ? customers[i] : 0;
            res = std::max(res, sum);
        }

        return res;
    }
};