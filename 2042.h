#include <string>

class Solution {
public:
    bool areNumbersAscending(std::string s) {
        s.push_back(' ');
        int prev_num = 0;
        int curr_num = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                for (int j = i + 1; j < s.size(); ++j)
                {
                    if (s[j] < '0' || s[j] > '9')
                    {
                        curr_num = std::stoi(s.substr(i, j - i + 1));
                        
                        if (curr_num <= prev_num)
                        {
                            return false;
                        }
                        else
                        {
                            prev_num = curr_num;
                            i = j;
                            break;
                        }
                    }
                }
            }
        }

        return true;
    }
};