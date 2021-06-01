#include <string>

class Solution {
public:
    std::string maxValue(std::string n, int x) {
        int index;
        for (index = 0; index < n.size(); ++index)
        {
            if (n.front() == '-')
            {
                if (n[index] - '0' > x) break;
            }
            else
            {
                if (n[index] - '0' < x) break;
            }
        }
        n.insert(index, 1, x + '0');

        return n;
    }
};