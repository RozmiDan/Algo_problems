#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matr(n,vector<int>(n, INF));
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
        matr[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int fst_val, scnd_val, thd_val;
        cin >> fst_val >> scnd_val >> thd_val;
        matr[--fst_val][--scnd_val] = thd_val;
        matr[scnd_val][fst_val] = thd_val;
    }

    for (int x = 0; x < n; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matr[i][x] >= INF || matr[x][j] >= INF)
                    continue;
                else {
                    matr[i][j] = min(matr[i][j], matr[i][x] + matr[x][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matr[i][j] < 10e8)
                max_len = max(max_len, matr[i][j]);
        }
    }

    cout << max_len;

    return 0;
}
