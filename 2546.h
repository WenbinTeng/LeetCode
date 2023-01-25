#include <string>

class Solution {
public:
    bool makeStringsEqual(std::string s, std::string target) {
        return (s.find('1') == std::string::npos) == (target.find('1') == std::string::npos);
    }
};