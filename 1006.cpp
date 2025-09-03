class Solution {
  public:
    int clumsy(int N) {
        int rec = N;
        int res = 0;

        for (; N > 3; N -= 4) {
            res += N * (N - 1) / (N - 2) * (rec == N ? 1 : -1) + N - 3;
        }

        if (N == 3)
            res += 6 * (rec == N ? 1 : -1);
        else if (N == 2)
            res += 2 * (rec == N ? 1 : -1);
        else if (N == 1)
            res += 1 * (rec == N ? 1 : -1);

        return res;
    }
};