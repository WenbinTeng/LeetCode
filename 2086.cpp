#include <string>

class Solution {
  public:
    int minimumBuckets(std::string hamsters) {
        int n = hamsters.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (hamsters[i] == '.') {
                if (i > 0 && hamsters[i - 1] == 'H') {
                    hamsters[i - 1] = 'x';
                    res++;
                    if (i < n - 1 && hamsters[i + 1] == 'H') {
                        hamsters[i + 1] = 'x';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (hamsters[i] == 'H') {
                if (i == 0)
                    return -1;
                else if (hamsters[i - 1] == 'H' || hamsters[i - 1] == 'x')
                    return -1;
                else if (hamsters[i - 1] == '.')
                    res++;
            }
        }

        return res;
    }
};