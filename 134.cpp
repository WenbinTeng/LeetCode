#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        gas[0] -= cost[0];
        for (int i = 1; i < gas.size(); ++i) {
            gas[i] = gas[i] - cost[i] + gas[i - 1];
        }
        return gas.back() < 0 ? -1
                              : (std::min_element(gas.begin(), gas.end()) -
                                 gas.begin() + 1) %
                                    gas.size();
    }
};