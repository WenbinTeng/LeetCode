#include <string>

class Solution {
  public:
    bool isLongPressedName(std::string name, std::string typed) {
        if (typed.size() < name.size())
            return false;

        int namePtr = 0;
        int typePtr = 0;

        while (typePtr < typed.size()) {
            if (name[namePtr] == typed[typePtr]) {
                namePtr++;
                typePtr++;
            } else if (namePtr > 0 && name[namePtr - 1] == typed[typePtr]) {
                typePtr++;
            } else {
                return false;
            }
        }

        return namePtr == name.size();
    }
};