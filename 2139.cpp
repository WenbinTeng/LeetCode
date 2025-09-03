class Solution {
  public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;

        while (target > 1) {
            if (maxDoubles) {
                if (target % 2 == 1)
                    ++res;
                ++res;
                target /= 2;
                --maxDoubles;
            } else {
                res += target - 1;
                break;
            }
        }

        return res;
    }
};