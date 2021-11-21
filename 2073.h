#include <vector>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int res = 0;
        int num = tickets[k];

        while (true)
        {
            for (int i = 0; i < tickets.size(); ++i)
            {
                if (tickets[i] != 0)
                {
                    --tickets[i];
                    ++res;
                }
                
                if (tickets[k] == 0) return res;
            }
        }

        return res;
    }
};