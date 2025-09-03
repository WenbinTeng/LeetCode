#include <string>
#include <vector>

class Solution {
  public:
    std::string decodeCiphertext(std::string encodedText, int rows) {
        std::string res = "";

        for (int i = 0, cols = encodedText.size() / rows; i < cols; ++i) {
            for (int j = 0; j < rows && i + j < cols; ++j) {
                int x = i + j;
                int y = j;
                res.push_back(encodedText[x + y * cols]);
            }
        }

        res.erase(res.find_last_not_of(" ") + 1);

        return res;
    }
};