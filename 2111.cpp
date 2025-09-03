#include <algorithm>
#include <vector>

class Solution {
  public:
    int kIncreasing(std::vector<int> &arr, int k) {
        int res = 0;

        for (int i = 0; i < k; ++i) {
            std::vector<int> tmp;

            for (int j = i; j < arr.size(); j += k) {
                tmp.push_back(arr[j]);
            }

            res += increasing(tmp);
        }

        return res;
    }

  private:
    int increasing(std::vector<int> &a) {
        std::vector<int> LIS;

        for (const auto e : a) {
            auto it = std::upper_bound(LIS.begin(), LIS.end(), e);

            if (it == LIS.end()) {
                LIS.push_back(e);
            } else {
                *it = e;
            }
        }

        return a.size() - LIS.size();
    }
};