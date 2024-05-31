#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][x] + matrix[x][j]);
            }
        }
    }

    int res = matrix[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res = max(res, matrix[i][j]);
        }
    }

    cout << res;

    return 0;
}
