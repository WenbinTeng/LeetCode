#include <vector>

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, std::vector<int>& energy, std::vector<int>& experience) {
        int needEnergy = 0;
        int needExperience = 0;

        for (const auto e : energy)
        {
            needEnergy += e;
        }
        needEnergy = std::max(needEnergy + 1 - initialEnergy, 0);

        for (int i = 0, c = initialExperience; i < experience.size(); ++i)
        {
            needExperience = std::max(needExperience, experience[i] + 1 - c);
            c += experience[i];
        }

        return needEnergy + needExperience;
    }
};