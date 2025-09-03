class Solution {
  public:
    int differenceOfSums(int n, int m) {
        int num2 = 0;
        for (int i = 1; i * m <= n; i++)
            num2 += i * m;
        return (n + 1) * n / 2 - num2 * 2;
    }
};