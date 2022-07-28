#include <vector>
#include <string>

class Solution {
public:
    std::string decodeMessage(std::string key, std::string message) {
        std::vector<char> alphabet(26, ' ');

        for (int i = 0, c = 'a'; i < key.size(); ++i)
        {
            if (key[i] != ' ' && alphabet[(int)key[i] - 'a'] == ' ')
            {
                alphabet[(int)key[i] - 'a'] = c;
                ++c;
            }
        }

        for (int i = 0; i < message.size(); ++i)
        {
            if (message[i] != ' ')
            {
                message[i] = alphabet[message[i] - 'a'];
            }
        }

        return message;
    }
};