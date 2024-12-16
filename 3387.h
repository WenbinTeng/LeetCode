#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    double maxAmount(std::string initialCurrency,
                     std::vector<std::vector<std::string>> &pairs1,
                     std::vector<double> &rates1,
                     std::vector<std::vector<std::string>> &pairs2,
                     std::vector<double> &rates2) {

        double res = 1;
        std::unordered_map<std::string, std::unordered_map<std::string, double>> matrix1;
        std::unordered_map<std::string, std::unordered_map<std::string, double>> matrix2;

        auto floyd =
            [](std::unordered_map<std::string, std::unordered_map<std::string, double>> &matrix,
               std::vector<std::vector<std::string>> &pairs,
               std::vector<double> &rates) {
                for (int i = 0; i < pairs.size(); i++) {
                    auto& u = pairs[i][0];
                    auto& v = pairs[i][1];
                    matrix[u][v] = rates[i];
                    matrix[v][u] = 1.0 / rates[i];
                }
                for (auto &[k, _] : matrix) {
                    matrix[k][k] = 1;
                }
                for (auto &[k, _] : matrix) {
                    for (auto &[u, _] : matrix) {
                        for (auto &[v, _] : matrix) {
                            if (matrix[u][v] < matrix[u][k] * matrix[k][v]) {
                                matrix[u][v] = matrix[u][k] * matrix[k][v];
                            }
                        }
                    }
                }
            };

        floyd(matrix1, pairs1, rates1);
        floyd(matrix2, pairs2, rates2);

        for (auto& [node1, rate1] : matrix1[initialCurrency]) {
            res = std::max(res, rate1 * matrix2[node1][initialCurrency]);
        }

        return res;
    }
};