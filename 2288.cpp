#include <string>

class Solution {
  public:
    std::string discountPrices(std::string sentence, int discount) {
        std::string res;
        int currPtr = 1;
        int nextPtr = 1;
        bool isNumber = true;
        sentence = ' ' + sentence + ' ';

        while (currPtr < sentence.size()) {
            if (sentence[currPtr] == '$' && sentence[currPtr - 1] == ' ') {
                int cnt = 0;
                isNumber = true;
                nextPtr = currPtr + 1;

                while (nextPtr < sentence.size() && sentence[nextPtr] != ' ') {
                    if (sentence[nextPtr] < '0' || sentence[nextPtr] > '9') {
                        isNumber = false;
                    }
                    if (cnt > 12) {
                        break;
                    }
                    ++cnt;
                    ++nextPtr;
                }

                if (isNumber && nextPtr > currPtr + 1) {
                    double discountNumber =
                        std::stoll(sentence.substr(currPtr + 1,
                                                   nextPtr - currPtr - 1)) *
                        (double)(100 - discount) / 100.0;
                    char buffer[14];
                    std::sprintf(buffer, "%.2lf", discountNumber);
                    std::string s(buffer);
                    res += '$' + s;
                    currPtr = nextPtr;
                } else {
                    res = res + sentence.substr(currPtr, nextPtr - currPtr);
                    currPtr = nextPtr;
                }
            } else {
                res.push_back(sentence[currPtr]);
                ++currPtr;
            }
        }

        res.pop_back();

        return res;
    }
};