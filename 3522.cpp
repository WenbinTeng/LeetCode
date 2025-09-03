#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    long long calculateScore(std::vector<std::string> &instructions,
                             std::vector<int> &values) {
        long long score = 0;
        int i = 0;
        int n = instructions.size();
        std::unordered_set<int> visited;

        while (i >= 0 && i < n && !visited.count(i)) {
            visited.insert(i);
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } else if (instructions[i] == "jump") {
                i += values[i];
            }
        }

        return score;
    }
};