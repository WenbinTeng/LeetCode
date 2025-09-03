#include <vector>

class Solution {
  public:
    int maxTurbulenceSize(std::vector<int> &arr) {
        if (arr.size() <= 1)
            return arr.size();

        int res = 1;
        int l = 0;
        int r = 0;
        int n = arr.size();

        while (r < n - 1) {
            if (l == r) {
                if (arr[l] == arr[l + 1]) {
                    l++;
                }
                r++;
            } else {
                if (arr[r - 1] < arr[r] && arr[r] > arr[r + 1] ||
                    arr[r - 1] > arr[r] && arr[r] < arr[r + 1]) {
                    r++;
                } else {
                    l = r;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};