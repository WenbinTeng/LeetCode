#include <vector>
#include <string>

class Solution {
public:
    int countPoints(std::string rings) {
        int res = 0;
        std::vector<std::vector<bool>> pos(10, std::vector<bool>(3, false));

        for (int i = 0; i < rings.size(); i += 2)
        {
            char color = rings[i];
            switch (color)
            {
            case 'R':
                pos[rings[i + 1] - '0'][0] = true;
                break;
            case 'G':
                pos[rings[i + 1] - '0'][1] = true;
                break;
            case 'B':
                pos[rings[i + 1] - '0'][2] = true;
                break;
            default:
                break;
            }
        }

        for (int i = 0; i < pos.size(); ++i)
        {
            if (pos[i][0] && pos[i][1] && pos[i][2]) ++res;
        }

        return res;
    }
};