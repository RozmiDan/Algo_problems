#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10e8;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            if(val != -1)
                matrix[i][j] = val;
            else
                matrix[i][j] = MAX;
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
            if(matrix[i][j] < 10e5)
                res = max(res, matrix[i][j]);
        }
    }

    cout << res;

    return 0;
}
