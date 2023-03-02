#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<std::string> getFolderNames(std::vector<std::string> &names) {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> um;

        for (const auto &name : names) {
            if (!um.count(name)) {
                res.push_back(name);
                um[name] = 1;
            } else {
                int k = um[name];
                while (um.count(addSuffix(name, k))) {
                    k++;
                }
                res.push_back(addSuffix(name, k));
                um[name] = k + 1;
                um[addSuffix(name, k)] = 1;
            }
        }

        return res;
    }

private:
    std::string addSuffix(std::string name, int k) {
        return name + "(" + std::to_string(k) + ")";
    }
};