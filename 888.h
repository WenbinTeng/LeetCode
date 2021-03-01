#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> fairCandySwap(std::vector<int>& A, std::vector<int>& B) {
        int sumA = 0;
        int sumB = 0;
        int delta = 0;
        std::unordered_set<int> us(A.begin(), A.end());

        for (const auto& iter : A) sumA += iter;
        for (const auto& iter : B) sumB += iter;

        delta = (sumA - sumB) / 2;

        for (const auto& iter : B)
        {
            if (us.find(iter + delta) != us.end()) return {iter + delta, iter};
        }

        return {};
    }
};