#include <vector>
#include <string>

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        int res = 0;
        int cnt = 0;
        int len = 0;
        int lastM = -1;
        int lastP = -1;
        int lastG = -1;

        for (int i = garbage.size() - 1; i >= 0; --i)
        {
            for (const auto c : garbage[i])
            {
                if (c == 'M' && lastM == -1) lastM = i;
                if (c == 'P' && lastP == -1) lastP = i;
                if (c == 'G' && lastG == -1) lastG = i;
            }

            if ((lastM | lastP | lastG) & 0x80000000 == 0) break;
        }

        for (int i = 0; i < garbage.size(); ++i)
        {
            cnt += garbage[i].size();
        }

        res += cnt;

        for (int i = 0; i < garbage.size(); ++i)
        {
            if (lastM == i) res += len;
            if (lastP == i) res += len;
            if (lastG == i) res += len;

            if (i < travel.size()) len += travel[i];
        }
        
        return res;
    }
};