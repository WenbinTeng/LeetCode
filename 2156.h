#include <string>
#include <vector>

class Solution {
public:
    std::string subStrHash(std::string s, int power, int modulo, int k, int hashValue) {
        int index = 0;
        int lSide = 0;
        int rSide = 0;
        long long currValue = 0;
        long long pk = 1;

        for (int i = s.size() - 1; i >= s.size() - k + 1; --i) {
            pk = (pk * power) % modulo;
            currValue = ((currValue + s[i] - 'a' + 1) * power) % modulo;
        }

        for (int i = s.size() - k; i >= 0; --i) {
            lSide = s[i] - 'a' + 1;
            rSide = s[i + k - 1] - 'a' + 1;
            currValue = (currValue + lSide) % modulo;
            if (currValue == hashValue)
                index = i;
            currValue = (power * (currValue + modulo - ((rSide * pk) % modulo))) % modulo;
        }

        return s.substr(index, k);
    }
};