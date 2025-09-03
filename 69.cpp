class Solution {
  public:
    int mySqrt(int x) {
        int res = -1;
        int l = 0;
        int r = x;

        while (l <= r) {
            int mid = (l + r) / 2;

            if ((long long)mid * mid <= x) {
                l = mid + 1;
                res = mid;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};