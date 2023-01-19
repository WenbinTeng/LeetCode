#include <string>
#include <unordered_set>

class Solution {
public:
    bool strongPasswordCheckerII(std::string password) {
        bool quantity = password.size() >= 8;
        bool upper = false;
        bool lower = false;
        bool digit = false;
        bool special = false;
        std::unordered_set<char> us = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

        for (int i = 0; i < password.size(); ++i) {
            auto c = password[i];
            upper |= (bool)std::isupper(c);
            lower |= (bool)std::islower(c);
            digit |= (bool)std::isdigit(c);
            special |= us.count(c);

            if (i > 0 && password[i - 1] == password[i])
                return false;
        }

        return quantity & upper & lower & digit & special;
    }
};