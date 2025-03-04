#include <string>

class Solution {
public:
    std::string smallestString(std::string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') {
                s[i] -= 1;
                int j = i + 1;
                while (j < n && s[j] != 'a') {
                    s[j++] -= 1;
                }
                return s;
            }
        }
        s[n - 1] = 'z';

        return s;
    }
};