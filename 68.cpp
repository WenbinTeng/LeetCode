#include <numeric>
#include <string>
#include <vector>

class Solution {
  public:
    std::vector<std::string> fullJustify(std::vector<std::string> &words,
                                         int maxWidth) {
        std::vector<std::string> res;
        std::vector<std::string> sel;

        int space = maxWidth + 1;
        int index = 0;

        while (index < words.size()) {
            if (space >= words[index].size() + 1) {
                space -= words[index].size() + 1;
                sel.push_back(words[index] + ' ');
                index++;
            } else {
                while (space > 0) {
                    if (sel.size() > 1) {
                        for (int i = 0; i < sel.size() - 1 && space--; i++)
                            sel[i].push_back(' ');
                    } else {
                        while (space--)
                            sel.back().push_back(' ');
                    }
                }

                std::string row =
                    std::accumulate(sel.begin(), sel.end(), std::string(""));
                row.pop_back();
                res.push_back(row);
                sel.clear();
                space = maxWidth + 1;
            }
        }

        if (!sel.empty()) {
            while (space--)
                sel.back().push_back(' ');
            std::string row =
                std::accumulate(sel.begin(), sel.end(), std::string(""));
            row.pop_back();
            res.push_back(row);
        }

        return res;
    }
};