#include <vector>
#include <string>

class Solution {
public:
    int countTexts(std::string pressedKeys) {
        long long res = 1;
        long long mod = 1e9 + 7;
        std::vector<long long> dp3(1e5 + 1);
        std::vector<long long> dp4(1e5 + 1);

        dp3[0] = 0;
        dp3[1] = 1;
        dp3[2] = 2;
        dp3[3] = 4;
        dp3[4] = 7;

        dp4[0] = 0;
        dp4[1] = 1;
        dp4[2] = 2;
        dp4[3] = 4;
        dp4[4] = 8;

        for (int i = 5; i <= 1e5; ++i)
        {
            dp3[i] = (dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % mod;
            dp4[i] = (dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % mod;
        }

        int l = 0;
        int r = 0;
        int cnt = 0;

        while (r < pressedKeys.size())
        {
            if (pressedKeys[l] == pressedKeys[r])
            {
                ++cnt;
                ++r;
            }
            else
            {
                if (pressedKeys[l] == '7' || pressedKeys[l] == '9')
                {
                    res = (res * dp4[cnt]) % mod;
                }
                else
                {
                    res = (res * dp3[cnt]) % mod;
                }
                l = r;
                cnt = 0;
            }
        }

        if (cnt != 0)
        {
            if (pressedKeys[l] == '7' || pressedKeys[l] == '9')
            {
                res = (res * dp4[cnt]) % mod;
            }
            else
            {
                res = (res * dp3[cnt]) % mod;
            }
        }

        return res;
    }
};