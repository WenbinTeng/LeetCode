#include <string>

class Solution {
public:
    std::string maximumTime(std::string time) {

        if (time[0] == '?' && time[1] == '?') {
            time[0] = '2';
            time[1] = '3';
        } else if (time[0] == '?')
            time[0] = time[1] >= '4' ? '1' : '2';
        else if (time[1] == '?')
            time[1] = time[0] == '2' ? '3' : '9';
        if (time[3] == '?')
            time[3] = '5';
        if (time[4] == '?')
            time[4] = '9';

        return time.substr(0, 5);
    }
};