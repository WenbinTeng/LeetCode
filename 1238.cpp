#include <cmath>
#include <vector>

class Solution {
  public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res(1 << n);
        for (int i = 0; i < res.size(); i++) {
            res[i] = (i >> 1) ^ i ^ start;
        }
        return res;
    }
};