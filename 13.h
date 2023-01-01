#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int prev = INT_MAX;
        int curr = INT_MAX;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            prev = curr;
            switch (s[i]) {
            case 'I':
                curr = 1;
                break;
            case 'V':
                curr = 5;
                break;
            case 'X':
                curr = 10;
                break;
            case 'L':
                curr = 50;
                break;
            case 'C':
                curr = 100;
                break;
            case 'D':
                curr = 500;
                break;
            case 'M':
                curr = 1000;
                break;
            default:
                curr = 0;
                break;
            }
            res += prev < curr ? curr - 2 * prev : curr;
        }

        return res;
    }
};