class Solution {
  public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;

        for (int i = 0; i < 32; i++) {
            int N = 1 << i;
            if (N > n) {
                return N - 1 - n;
            }
        }

        return 0;
    }
};