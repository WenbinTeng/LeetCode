#include <vector>

class NumMatrix {
  public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {
        if (matrix.empty())
            return;

        int m = matrix.size();
        int n = matrix[0].size();

        record = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    record[i][j] = matrix[i][j];
                else if (i == 0) {
                    record[i][j] = record[i][j - 1] + matrix[i][j];
                    continue;
                } else if (j == 0) {
                    record[i][j] = record[i - 1][j] + matrix[i][j];
                    continue;
                } else
                    record[i][j] = record[i - 1][j] + record[i][j - 1] -
                                   record[i - 1][j - 1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (record.empty())
            return 0;

        if (row1 == 0 && col1 == 0)
            return record[row2][col2];
        else if (row1 == 0)
            return record[row2][col2] - record[row2][col1 - 1];
        else if (col1 == 0)
            return record[row2][col2] - record[row1 - 1][col2];
        else
            return record[row2][col2] - record[row2][col1 - 1] -
                   record[row1 - 1][col2] + record[row1 - 1][col1 - 1];
    }

  private:
    std::vector<std::vector<int>> record;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */