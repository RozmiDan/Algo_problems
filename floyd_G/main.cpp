#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matr(n,vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matr[i][j];
        }
    }

    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matr[i][x] + matr[x][j] == 2)
                    matr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
