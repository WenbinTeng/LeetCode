#include <string>

class Solution {
public:
    int countValidWords(std::string sentence) {
        int res = -1;
        bool isWord = true;
        bool hasSign = false;
        bool hasDash = false;

        sentence = " " + sentence + " ";

        for (int i = 0; i < sentence.size(); ++i)
        {
            if (sentence[i] >= '0' && sentence[i] <= '9')
            {
                isWord = false;
            }
            else if (sentence[i] == '-')
            {
                if (sentence[i - 1] < 'a' || sentence[i - 1] > 'z' || sentence[i + 1] < 'a' || sentence[i + 1] > 'z') isWord = false;
                if (hasDash) isWord = false;
                hasDash = true;
            }
            else if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',')
            {
                if (sentence[i + 1] != ' ') isWord = false;
                if (hasSign) isWord = false;
                hasSign = true;
            }
            else if (sentence[i] == ' ')
            {
                while (i + 1 < sentence.size() && sentence[i + 1] == ' ') ++i;

                if (isWord) ++res;

                isWord = true;
                hasSign = false;
                hasDash = false;
            }
        }

        return res;
    }
};