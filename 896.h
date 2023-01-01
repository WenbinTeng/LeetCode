#include <vector>

class Solution {
public:
    bool isMonotonic(std::vector<int> &A) {
        if (A.size() == 1)
            return true;

        int index = 1;
        while (index < A.size() && A[index - 1] == A[index])
            ++index;

        if (index == A.size())
            return true;

        if (A[index - 1] <= A[index]) {
            for (int i = index + 1; i < A.size(); ++i)
                if (A[i - 1] > A[i])
                    return false;
        }
        if (A[index - 1] >= A[index]) {
            for (int i = index + 1; i < A.size(); ++i)
                if (A[i - 1] < A[i])
                    return false;
        }

        return true;
    }
};