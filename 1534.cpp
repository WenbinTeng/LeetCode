#include <algorithm>
#include <vector>

class Solution {
  public:
    int countGoodTriplets(std::vector<int> &arr, int a, int b, int c) {
        int n = arr.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (std::abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < n; k++) {
                        if (std::abs(arr[j] - arr[k]) <= b &&
                            std::abs(arr[i] - arr[k]) <= c) {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }
};