#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> NumMatrix(vector<vector<int>>& matrix)
{
    size_t n = matrix.size();
    size_t m = matrix[0].size();
    vector<vector<int>> result(n, vector<int>(m,0));

    //counting 2d prefix sum
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if(i == 0 && j == 0)
                continue;

            else if(j == 0)
                matrix[i][j] += matrix[i-1][j];

            else if(i == 0)
                matrix[i][j] += matrix[i][j-1];

            else {
                matrix[i][j] = matrix[i][j] + matrix[i][j-1]
                        + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
    }

    return matrix;
}

int sumRegion(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2)
{
    int res_sum = 0;

    if(row1 == 0 && col1 == 0)
        res_sum = matrix[row2][col1];

    else if (row1 == 0)
        res_sum = matrix[row2][col2] - matrix[row2][col1 - 1];

    else if (col1 == 0)
        res_sum = matrix[row2][col2] - matrix[row1 - 1][col2];

    else
        res_sum = matrix[row2][col2] - matrix[row2][col1 - 1]
                - matrix[row1 - 1][col2] + matrix[row1 - 1][col1 - 1];

    return res_sum;
}

int main()
{
    vector<vector<int>>mat{{-4,5}};
    mat = NumMatrix(mat);
    cout << sumRegion(mat,0,0,0,1);
    return 0;
}
