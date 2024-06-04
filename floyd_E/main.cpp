#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    bool flag_minus = false;
    int min_val = 10e8;

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

    for (int i = 0; i < n; ++i) {

        if(matrix[i][i] < 0) {
            flag_minus = true;
            break; }

        for (int j = 0; j < n; ++j) {
            if(i != j)
                min_val = min(min_val, matrix[i][j]);
        }

    }

    if(flag_minus)
        cout << -1;
    else
        cout << min_val;

    return 0;
}
